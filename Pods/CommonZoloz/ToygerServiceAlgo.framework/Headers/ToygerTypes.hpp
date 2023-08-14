/***
 * Toyger基础数据结构定义
 */

#pragma once
#include <string>

extern "C"
{
    //整形Rect
    struct TGIRect
    {
        int left = 0;
        int top = 0;
        int right = 0;
        int bottom = 0;
        inline TGIRect() {}
        inline TGIRect(int l, int t, int r, int b)
        {
            left = l;
            top = t;
            right = r;
            bottom = b;
        }
    };

    //浮点型Rect
    struct TGFRect
    {
        float left = 0.;
        float top = 0.;
        float right = 0.;
        float bottom = 0.;
        inline TGFRect(float l = 0.f, float t = 0.f, float r = 0.f, float b = 0.f)
        {
            left = l;
            top = t;
            right = r;
            bottom = b;
        }
    };

    //浮点型Point
    struct TGPoint
    {
        float x = 0.;
        float y = 0.;
    };

    //调用方传进来的帧数据格式
    enum TGFrameFormat
    {
        TG_Frame_Format_YUV = 0,
        TG_Frame_Format_BGRA = 1,
        TG_Frame_Format_BGR = 2,
        TG_Frame_Format_RGBA = 3,
        TG_Frame_Format_RGB = 4,
        TG_Frame_Formate_Unknown = 9999,
    };

    //调用方传进来的帧数据类型
    enum TGFrameType
    {
        TG_Frame_Light = 0, //亮帧
        TG_Frame_Dark,      //暗帧
        TG_Frame_Nano,      //剪裁的小图
        TG_Frame_Unknown = 9999
    };

    //帧数据
    class TGFrame
    {
    public:
        TGFrame();
        TGFrame(int w, int h, int angle, TGFrameFormat color_space, TGFrameType brightness);
        TGFrame(unsigned char *data, int w, int h, int angle, TGFrameFormat color_space, TGFrameType brightness, bool copy = true);
        ~TGFrame();
        TGFrame(const TGFrame &src);
        TGFrame &operator=(const TGFrame &src);
        TGFrame clone() const;
        bool empty() const;
        unsigned char *image_data;
        long data_len;
        int width;
        int height;
        int rotation;
        std::string sensor_data;
        TGFrameFormat format;
        TGFrameType frame_type;

    private:
        int getDataLen() const;
        void Ref();
        int UnRef();
        bool _own;
        int *_use = nullptr; // todo: not thread safe
    };

    //HandleEventTriggered 回调函数返回码定义
    enum TGEventCode
    {
        TG_Event_Code_Monitor = 2,      //埋点事件
        TG_Event_Code_Log = 1,          //诊断日志事件
        TG_Event_Code_Dark_Screen = -1, //调暗屏幕事件
        TG_Event_Code_Action_Start = -10,//挑战动作开始
        TG_Event_Code_Action_End = -11,  //挑战结束
        TG_Event_Code_Log_Status_Change = -12, //埋点faceStatusChange
        TG_Event_Code_Log_Status_key = -13, //埋点faceinokey
        TG_Event_Code_Challenge_Pose_End = -14, //多动作姿态校验结束回调
        TG_Event_Code_Photinus_Start = -15,//炫彩切换颜色事件
        TG_Event_Code_No_Face_Detected = -16,//没脸，清空炫彩状态
    };

    enum TGResultCode
    {
        TG_Result_Success = 0,   //成功结束
        TG_Result_Liveness_Fail, //活体检测失败
        TG_Result_Error          //内部逻辑错误
    };
}
