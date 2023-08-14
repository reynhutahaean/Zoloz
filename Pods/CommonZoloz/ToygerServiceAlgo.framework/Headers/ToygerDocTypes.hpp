#pragma once
#include "ToygerTypes.hpp"

extern "C"
{
    //证件算法配置
    struct TGDocConfig
    {
        std::string doc_type = "";  //证件类型
        int page = 0;               //证件页码
        std::string sub_type = "";  //当前采集类型[docimage|flashimage|angleimage]
        int capture_mode = 1;        //0手拍，1轻奢 2 豪华
        float doc_threshold = {0.}; //边阈值
        float face_threshold = 30;  //证件上的人脸阈值
        int thickness;              //算法阈值
        int log_level = 0;          //日志级别
        float corners[8] = {0.};    //frame四个角点坐标，tl.x tl.y, tr.x, tr.y, br.x br.y bl.x bl.y
        int flash_time = 500;       //闪光灯计时器，ms单位
        TGFRect face_roi = {0.f};   //人脸检测区域
        int stack_time = 1000;      //证件累积时间
        int fancy_checkface = -1;   //豪华版是否检测人脸

        float blurMin = 0.1;
        float reflectionMin = 0;
        float occlusionMin = 0;
        float shadowMin = 0;
        float integrityMin = 0;
        float distanceMax =0.4;
        float distanceMin = 0.15;
        float pitchMax = 0.2;
        float pitchMin = -0.2;
        float yawMax = 0.2;
        float yawMin =  -0.2;
        float lightSpot = 0.5;
        float lightSpotMin = 0.1;

        std::string path = "";

        inline TGDocConfig() {}

        inline TGDocConfig(const std::string &type, const std::string &sub, int pg, float d, float f, int t, int l, float *c, int flash, const TGFRect &roi, int stack, std::string p, float pblurMin,float preflectionMin,float pocclusionMin,float pshadowMin,float pintegrityMin,float pdistanceMax,float pdistanceMin,float ppitchMax,float ppitchMin,float pyawMax,float pyawMin,int pcapturemode,int pdetectFace, float  plightSpot, float  plightSpotMin)
        {
            doc_type = type;
            sub_type = sub;
            page = pg;
            doc_threshold = d;
            face_threshold = f;
            thickness = t;
            log_level = l;
            corners[0] = c[0];
            corners[1] = c[1];
            corners[2] = c[2];
            corners[3] = c[3];
            corners[4] = c[4];
            corners[5] = c[5];
            corners[6] = c[6];
            corners[7] = c[7];
            flash_time = flash;
            face_roi = roi;
            stack_time = stack;
            path = p;
            
            blurMin = pblurMin;
            reflectionMin = preflectionMin;
            occlusionMin = pocclusionMin;
            shadowMin = pshadowMin;
            integrityMin = pintegrityMin;
            distanceMax = pdistanceMax;
            distanceMin = pdistanceMin;
            pitchMax = ppitchMax;
            pitchMin = ppitchMin;
            yawMax = pyawMax;
            yawMin = pyawMin;
            capture_mode = pcapturemode;
            fancy_checkface = pdetectFace;
            lightSpotMin = plightSpotMin;
            lightSpot = plightSpot;

        }

        inline TGDocConfig &operator=(const TGDocConfig &rhs)
        {
            if (&rhs == this)
                return *this;
            doc_type = rhs.doc_type;
            sub_type = rhs.sub_type;
            page = rhs.page;
            doc_threshold = rhs.doc_threshold;
            face_threshold = rhs.face_threshold;
            thickness = rhs.thickness;
            log_level = rhs.log_level;
            corners[0] = rhs.corners[0];
            corners[1] = rhs.corners[1];
            corners[2] = rhs.corners[2];
            corners[3] = rhs.corners[3];
            corners[4] = rhs.corners[4];
            corners[5] = rhs.corners[5];
            corners[6] = rhs.corners[6];
            corners[7] = rhs.corners[7];
            flash_time = rhs.flash_time;
            sub_type = rhs.sub_type;
            face_roi = rhs.face_roi;
            stack_time = rhs.stack_time;
            path = rhs.path;

            blurMin = rhs.blurMin;
            reflectionMin = rhs.reflectionMin;
            occlusionMin = rhs.occlusionMin;
            shadowMin = rhs.shadowMin;
            integrityMin = rhs.integrityMin;
            distanceMax = rhs.distanceMax;
            distanceMin = rhs.distanceMin;
            pitchMax = rhs.pitchMax;
            pitchMin = rhs.pitchMin;
            yawMax = rhs.yawMax;
            yawMin = rhs.yawMin;
            capture_mode = rhs.capture_mode;
            fancy_checkface = rhs.fancy_checkface;
            lightSpot = rhs.lightSpot;
            lightSpotMin = rhs.lightSpotMin;
            return *this;
        };
    };

    //证件属性
    struct TGDocAttr
    {
        std::string doc_type = "";
        std::string sub_type = "";
        int page = 0;
        float top_score = 0.;
        float right_score = 0.;
        float bottom_score = 0.;
        float left_score = 0.;
        float face_score = 0.;
        
        float blur_score = 0.;
        float reflection_score = 0.;
        float occlusion_score = 0.;
        float shadow_score = 0.;
        float integrity_score = 0.;
        float distance_score = 0.;
        float pitch_score = 0.;
        float yaw_score = 0.;
        float roll_score = 0.;
       

        inline TGDocAttr(){};
        inline TGDocAttr(const std::string &type, const std::string &sub, int pg, float t, float r, float b, float l, float face)
        {
            doc_type = type;
            sub_type = sub;
            page = pg;
            top_score = t;
            right_score = r;
            bottom_score = b;
            left_score = l;
            face_score = face;
        }

        inline TGDocAttr(const std::string &type, const std::string &sub, int pg, float t, float r, float b, float l, float face,float blur,float reflection,float occlusion,float shadow,float integrity,float distance,float pitch,float yaw,float roll)
        {
            doc_type = type;
            sub_type = sub;
            page = pg;
            top_score = t;
            right_score = r;
            bottom_score = b;
            left_score = l;
            face_score = face;

            blur_score = blur;
            reflection_score = reflection;
            occlusion_score = occlusion;
            shadow_score = shadow;
            integrity_score = integrity;
            distance_score = distance;
            pitch_score = pitch;
            yaw_score = yaw;
            roll_score = roll;

        }
    };

    enum TGDOCMessage
    {       
        TGDOCMessage_NO_CARD = 0, // 没有证件
        TGDOCMessage_TOO_FAR = 1, // 距离手机太远
        TGDOCMessage_TOO_CLOSE = 2, // 距离手机太近
        TGDOCMessage_INTEGRITY = 3, // 证件不完整
        TGDOCMessage_TILTING = 4, //  手机倾斜
        TGDOCMessage_SHADOW = 5, // 有阴影
        TGDOCMessage_OCCLUSION = 6, // 证件有遮挡
        TGDOCMessage_REFLECTION = 7, // 证件有反光
        TGDOCMessage_BLUR = 8, // blur
        TGDOCMessage_STACK_TIME = 9,// 请保持
        TGDOCMessage_WRONG_CARD = 10, //证件脸的校验没通过
    };

    //证件状态
    struct TGDocState
    {
        bool hasDoc = false;  //是否有证件
        bool hasFace = false; //证件上是否有人脸
        bool t = false;       //上边证件是否OK
        bool r = false;       //右边证件是否OK
        bool b = false;       //下边证件是否OK
        bool l = false;       //左边证件是否OK
        bool lightSpot = false;
        float corners[8] = {0.};    //frame四个角点坐标，tl.x tl.y, tr.x, tr.y, br.x br.y bl.x bl.y
        TGDOCMessage message; 
        inline TGDocState(){};
        inline TGDocState(bool d, bool f, bool t, bool r, bool b, bool l)
        {
            this->hasDoc = d;
            this->hasFace = f;
            this->t = t;
            this->r = r;
            this->b = b;
            this->l = l;
        }
        inline TGDocState(bool d, bool light, float c0, float c1, float c2, float c3, float c4, float c5, float c6,float c7,TGDOCMessage m)
        {
            this->hasDoc = d;
            this->lightSpot = light;
            this->corners[0] = c0;
            this->corners[1] = c1;
            this->corners[2] = c2;
            this->corners[3] = c3;
            this->corners[4] = c4;
            this->corners[5] = c5;
            this->corners[6] = c6;
            this->corners[7] = c7;
            this->message = m;
        }
        
        
    };



    struct TGDocInfo
    {
        TGFrame frame;
        TGDocAttr attr;
    };
}