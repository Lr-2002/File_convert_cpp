// An example of sending OpenCV webcam frames into a MediaPipe graph.
#include <cstdlib>

#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/formats/image_frame.h"
#include "mediapipe/framework/formats/image_frame_opencv.h"
#include "mediapipe/framework/port/commandlineflags.h"
#include "mediapipe/framework/port/file_helpers.h"
#include "mediapipe/framework/port/opencv_highgui_inc.h"
#include "mediapipe/framework/port/opencv_imgproc_inc.h"
#include "mediapipe/framework/port/opencv_video_inc.h"
#include "mediapipe/framework/port/parse_text_proto.h"
#include "mediapipe/framework/port/status.h"
#include<iostream>
constexpr char kInputStream[] = "input_video";
constexpr char kOutputStream[] = "output_video";
constexpr char kWindowName[] = "MediaPipe";

DEFINE_string(
        calculator_graph_config_file, "",
"Name of file containing text format CalculatorGraphConfig proto.");

class PL
{
public:
    std::string calculator_graph_config_contents;
    mediapipe::CalculatorGraph graph;
    mediapipe::CalculatorGraphConfig config;
    cv::VideoCapture capture;
    PL()=default;
    mediapipe::Status get_cal_config()
    {
        std::cout<<"get_cal_config"<<std::endl;
        MP_RETURN_IF_ERROR(mediapipe::file::GetContents(
                FLAGS_calculator_graph_config_file, &calculator_graph_config_contents));
        std::cout<<calculator_graph_config_contents<<std::endl;

        LOG(INFO) << "Get calculator graph config contents: "
                  << calculator_graph_config_contents;
        config =
                mediapipe::ParseTextProtoOrDie<mediapipe::CalculatorGraphConfig>(
                        calculator_graph_config_contents);
        std::cout<<"get_cal_config"<<std::endl;

    }

    mediapipe::Status initialize()
    {
        std::cout<<"initialize";
        LOG(INFO) << "Initialize the calculator graph.";
        MP_RETURN_IF_ERROR(graph.Initialize(config));
    }

    mediapipe::Status camera()
    {
        std::cout<<"camera";
        capture.open(0);
        RET_CHECK(capture.isOpened());
    }

    mediapipe::Status start_running() {
        std::cout << "start_running";
        LOG(INFO) << "Start running the calculator graph.";
        ASSIGN_OR_RETURN(mediapipe::OutputStreamPoller
        poller,
                graph.AddOutputStreamPoller(kOutputStream));
        MP_RETURN_IF_ERROR(graph.StartRun({}));

        LOG(INFO) << "Start grabbing and processing frames.";


        // Capture opencv camera or video frame.

        cv::Mat camera_frame_raw = cv::imread("E:\\work\\piano_test\\mediapipe-1\\test.jpg");
        std::cout<<std::endl<<"image_empty"<<camera_frame_raw.empty()<<std::endl;
        cv::Mat camera_frame;
        cv::cvtColor(camera_frame_raw, camera_frame, cv::COLOR_BGR2RGB);


        // Wrap Mat into an ImageFrame.
        auto input_frame = absl::make_unique<mediapipe::ImageFrame>(
                mediapipe::ImageFormat::SRGB, camera_frame.cols, camera_frame.rows,
                mediapipe::ImageFrame::kDefaultAlignmentBoundary);
        cv::Mat input_frame_mat = mediapipe::formats::MatView(input_frame.get());
        camera_frame.copyTo(input_frame_mat);

        // Send image packet into the graph.
        size_t frame_timestamp_us =
                (double) cv::getTickCount() / (double) cv::getTickFrequency() * 1e6;
        MP_RETURN_IF_ERROR(graph.AddPacketToInputStream(
                kInputStream, mediapipe::Adopt(input_frame.release())
                        .At(mediapipe::Timestamp(frame_timestamp_us))));

        // Get the graph result packet, or stop if that fails.
        mediapipe::Packet packet;
        auto &output_frame = packet.Get<mediapipe::ImageFrame>();

        // Convert back to opencv for display or saving.
        cv::Mat output_frame_mat = mediapipe::formats::MatView(&output_frame);
        cv::cvtColor(output_frame_mat, output_frame_mat, cv::COLOR_RGB2BGR);

        cv::imshow(kWindowName, output_frame_mat);
        cv::waitKey(0);
        // Press any key to exit.


    }
    mediapipe::Status shut_down()
    {
        MP_RETURN_IF_ERROR(graph.CloseInputStream(kInputStream));
    }
};
int main(int argc,char ** argv)
{
    google::InitGoogleLogging(argv[0]);
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    PL a;

    a.get_cal_config();
    std::cout<<"testing";
    a.initialize();
    a.camera();
    a.start_running();
    a.shut_down();
    return 0;

}
