#pragma once
#include "ToygerTypes.hpp"

extern "C"
{
    //通用配置
    struct TGCommonConfig
    {
        int log_level; //日志级别，0 - None, 1 - light, 2 - heavy
    };

    //质量相关参数配置
    struct TGQualityConfig
    {
        float min_brightness = 0.3;  //脸部最低亮度
        float min_face_width = 0.25; //脸部最低宽度，face++算法下通过这个参数判断距离，zisa算法下通过iod来判断距离
        float min_integrity = 0.9;   //脸部区域完整度
        float min_pitch = -0.2;      //最小俯仰角
        float max_pitch = 0.2;       //最大俯仰角
        float min_yaw = -0.2;        //最小偏转角
        float max_yaw = 0.2;         //最大偏转角
        float max_gaussian = 0.15;   //最大高斯模糊
        float max_motion = 0;        //最大运动模糊（目前算法没有返回）
        float min_quality = 20;      //最低人脸质量
        float min_iod = 0.18;        //最小iod，通过这个参数来判断距离
        bool dynamic_iod = false;    //是否需要动态改变iod，false: 不变；true: 动态改变
        float max_iod = 0.45;        //最大iod，通过这个参数来判断距离
        float stack_time = 2.f;      //用户保持合适姿势的最短时间
        float blink_openness = 0.2;  //眨眼检测阈值
        float eye_openness = 0.2;    //眼睛睁开阈值[not used]
        float diff_threshold = 0.5;  //眨眼阈值 
        float openness_threshold_aux = 0.05;//bink模型眨眼阈值[黑人脸新增]
        float diff_threshold_aux = 0.15;//bink模型眨眼阈值[黑人脸新增]
        float quality_stability_threshold = 0.01;//[黑人脸新增]
        float eye_occlusion_score_threshold = 0.5;//眼部遮挡阈值【多动作新加】
        float pts_occ_num_threshold = 10;//脸部关键点遮挡阈值【多动作新加】
        float face_confidence_threshold = -1;// 多人脸检测阈值
    };

    //活体相关参数配置
    struct TGLivenessConfig
    {
        std::string liveness_combinations = "NoLiveness"; //活体组合，`#`分割，如"fpp_blink#yunqi_blink#dragonfly#gemini"
        std::string collection;                           //采集组合，`#`分割，如"Pano#Nano"
        float dragonfly_min;                              //dragonfly活体算法最低阈值
    };

    //摇头的方向
    enum TGHeadMoveOrientation
    {
        TGHeadMoveOrientation_Up = 0,
        TGHeadMoveOrientation_Up_Right = 1,
        TGHeadMoveOrientation_Right = 3,
        TGHeadMoveOrientation_Right_Down = 4,
        TGHeadMoveOrientation_Down = 6,
        TGHeadMoveOrientation_Down_Left = 7,
        TGHeadMoveOrientation_Left = 9,
        TGHeadMoveOrientation_Left_Up = 10,  
    };
    struct TGLiveness_action
    {
        int index = 0;
        std::string name = "";
        std::vector<std::string> collection; //约定上传blob里的extinfo内容，包括exif，sensor 等
        float headMove_left = 0.15f;
        float headMove_right = -0.15;
        float headMove_down = 0.13f;
        float headMove_up = -0.13;
        int   headMove_orientation = 0;
        float mouthOpen_open = 0.2f;
        float mouthOpen_diff = 0.4f;
        float middle_iod = 0.28f;     // middle iod，用于Falcon算法，在动态调整人脸远近时用到
        float margin_iod = 0.02f;     // margin iod，用于Falcon算法，在动态调整人脸远近时用到
        std::string color_seq;        // 每个颜色以,分割
    };

    //调用方需要传进来的配置
    struct TGConfig
    {
        TGQualityConfig quality_config;   //质量配置
        TGLivenessConfig liveness_config; //活体配置
        std::vector<TGLiveness_action> action;     //多动作配置
        TGCommonConfig common_config;     //通用配置
        int ui_type;                      // 当前算法 UI Type
        std::vector<std::string> data_collection;  //约定需要采集的帧信息
        inline TGConfig &operator=(const TGConfig &rhs)
        {
            if (&rhs == this)
            {
                return *this;
            }
            this->quality_config = rhs.quality_config;
            this->liveness_config = rhs.liveness_config;
            this->common_config = rhs.common_config;
            this->action = rhs.action;
            this->ui_type = rhs.ui_type;
            this->data_collection = rhs.data_collection;
            return *this;
        }
    };

    //人脸属性
    struct TGFaceAttr
    {
        bool has_face = false;                  //是否检测到人脸
        bool eye_blink = false;                 //当前帧是否眨眼
        TGFRect face_region;                    //人脸区域，portrait角度归一化矩形区域
        float quality = 0.;                     //人脸质量分
        float yaw = 0.;                         //偏转角
        float pitch = 0.;                       //俯仰角
        float gaussian = 0.;                    //高斯模糊
        float motion = 0.;                      //运动模糊（未启用）
        float brightness = 0.;                  //人脸区域亮度
        float distance = 0.;                    //人脸距离
        float integrity = 0.;                   //人脸完整度
        float left_eye_blink_ratio = 0.;        //左眼张开程度
        float right_eye_blink_ratio = 0.;       //右眼张开程度
        float keypts[10];                       //人脸关键点
        bool eye_open = false;                  //眼睛是否张开
        float confidence = 0.;                  //人脸检测置信度
        float iodRatio = 0.;                    //iod距离
        float roll = 0.;                        //滚转角
        bool mouth_open = false;                //张嘴
        bool eyeBlinkAux = false;                //辅助算法的眨眼
        float stability = 0.;                    //质量分之关键点稳定程度
        float leftEyeOpenScoreAux = 0.;          //辅助算法的左眼张开程度
        float rightEyeOpenScoreAux = 0.;         //辅助算法的右眼张开程度
        float mouthOpenScore = 0.;               //张嘴分
        float pts_occ_num = 0;                     // 遮挡的关键点数目
        float leftEyeOccProb = 0;                // 左眼被遮挡的概率
        float rightEyeOccProb = 0;               // 右眼被遮挡的概率
        float colorWarm = 0;                     //
        float colorCold = 0;                     //
        float p0 = 0;                            // 多动作起始 pitch 值
        float y0 = 0;                            // 多动作起始 yaw 值
        bool face_occlusion = false;             // 是否有人脸遮挡
        std::string type;                        // 为了区分由算法返回的图是什么类型，在 TGFaceAttr 中添加
                                                 // type 字段，来表示当前图片为哪一帧数据
        inline TGFaceAttr(){};
    };

    //根据人脸算法吐出的每一帧属性结合参数阈值，判断的当前人脸状态
    //结合每个属性的优先级判断调用方应该给用户的提示
    enum TGMessage
    {
        TG_Message_Image_Perfect = 0,  //完成采集，算法处理结束
        TG_Message_No_Face,            //没有检测到人脸
        TG_Message_Distance_Too_Far,   //人脸太远了
        TG_Message_Distance_Too_Close, //人脸太近了
        TG_Message_Face_Not_In_Center, //人脸不在画面中间
        TG_Message_Bad_Pitch,          //用户抬头或者低头
        TG_Message_Bad_Yaw,            //用户在转头
        TG_Message_Is_Moving,          //用户在动
        TG_Message_Bad_Brightness,     //环境太暗了
        TG_Message_Bad_Quality,        //人脸质量太低
        TG_Message_Bad_Eye_Openness,   //没有睁眼
        TG_Message_Blink_Openness,     //用户闭眼
        TG_Message_Stack_Time,         //还没有保持足够时间
        TG_Message_Head_Up,            //往上抬头
        TG_Message_Head_Up_Right,      //右上抬头
        TG_Message_Head_Right,         //右转头
        TG_Message_Head_Right_Down,    //右下转头
        TG_Message_Head_Down,          //低头
        TG_Message_Head_Down_Left,     //左下转头
        TG_Message_Head_Left,          //左转头
        TG_Message_Head_Left_Up,       //左上转头
        TG_Message_Mouth_Open,         //张嘴
        TG_Message_ACTION_SWITCH,      //完成一个动作
    };

    //Toyger根据根据活体算法组合推断出的应该给用户提示的静态文案
    enum TGStaticMessage
    {
        TGStaticMessage_NoLiveness = 0, //无活体
        TGStaticMessage_BlinkLiveness,  //需要用户眨眼
    };


    //结合算法输出和调用方的参数配置生成的每一帧状态
    //int的属性：-1代表低于阈值，1代表高于阈值
    struct TGFaceState
    {
        TGMessage tip_message = TG_Message_No_Face;                  //给用户提示的动态文案
        TGStaticMessage static_message = TGStaticMessage_NoLiveness; //给用户提示的静态文案
        bool has_face = false;                                       //是否检测到人脸
        int brightness = 0;                                          //亮度是否满足阈值
        int distance = 0;                                            //距离是否满足阈值
        bool face_in_center = false;                                 //人脸是否在图像中间
        bool is_moving = false;                                      //用户是否在动
        bool good_quality = false;                                   //图片质量是否满足阈值
        int good_pitch = 0;                                          //俯仰角是否满足阈值
        int good_yaw = 0;                                            //偏转角是否满足阈值
        bool eye_openness = false;                                   //眼睛是否睁开
        bool blink_openness = false;                                 //是否眨眼
        float current_progress = 0;                                  //当前进度评估，0代表进度很差，1代表完成采集
        float ballProgress = 0;                                      //小球移动百分比，0代表没有移动，1代表完成
        bool face_occlusion = false;             // 是否有人脸遮挡
        int iod_ui = 0;                          //用来标识当前是否需要将 UI 放大还是缩小，0 不变 1 放大 2 缩小
        TGHeadMoveOrientation orientation;                           //小球移动方向（时钟表盘，0点方向表示向上，1点方向表示右上，3点方向表示向右，4点方向表示右下，6点方向表示向下，7点方向表示左下，9点方向表示向左，10点方向表示左上）
    };

    //人脸数据
    struct TGFaceInfo
    {
        TGFrame frame; //图片帧数据
        TGFaceAttr attr;   //图片人脸属性
    };
}