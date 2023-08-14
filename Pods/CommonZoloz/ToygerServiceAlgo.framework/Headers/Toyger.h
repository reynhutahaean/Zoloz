/***
 * Toyger对外接口
 */
#pragma once
#include <string>
#include <vector>
#include <map>
#include "ToygerFaceTypes.hpp"

#ifdef __cplusplus
extern "C"
{
#endif
    //状态回调
    struct ToygerCallback
    {
        //算法处理结束 **一次业务只会回调一次**
        //@param cb_receiver:调用方在config时传入的指针,调用方可以通过这个指针绑定到调用config接口的实例
        //@param code:处理结果
        //@param infos:采集的图片数组，每一个图片的类型通过frame.type进行解析
        //@param ext:扩展参数，目前把高清亮帧的图片质量返回，key值为“quality”
        void (*handleFinish)(void *cb_receiver, TGResultCode code, const std::vector<TGFaceInfo> &info, const std::map<std::string, std::string> &ext);

        //状态回调 **每一帧调用一次**
        //@param cb_receiver:调用方在config时传入的指针,调用方可以通过这个指针绑定到调用config接口的实例
        //@param state:当前状态，调用方可以根据该参数进行交互提示
        //@param attr:当前属性
        void (*handleUpdate)(void *cb_receiver, const TGFaceState &state, const TGFaceAttr &attr);

        //事件回调 **事件发生时触发回调**
        //@param cb_receiver:调用方在config时传入的指针,调用方可以通过这个指针绑定到调用config接口的实例
        //@param event_code:事件类型
        //@param log:诊断/埋点日志
        //@param buffer: 二进制数据
        //@param buffer_length: 二进制数据长度
        void (*handleEvent)(void *cb_receiver, TGEventCode event_code, const char *log, const unsigned char *buffer, int buffer_length);
    };

    //Toyger接口

    //[同步]初始化toyger模块，进行模型加载、license校验、bundleId校验等操作
    //@param model[nonnullable]:算法模型数据
    //@param license[nullable]:license数据，如果SDK编译时开启了license校验，则该参数必须传入，否则可以不传
    //@param bundleId[nullable]:bundleId，如果SDK编译时开启了license校验，则该参数必须传入，否则可以不传
    //@param tg_instance[nullable]:如果初始化成功，该参数会指向toyger实例，作为后续接口调用的入参，如果失败，则该参数为空
    //@return: 如果初始化成功，则返回true，反之返回false
    bool tg_init(const std::vector<uint8_t> &model, const std::string &license, const std::string &bundleid, void **tg_instance);

    //[同步]向toyger传入配置参数以及回调信息等
    //@param tg_instance[nonnullable]:init时初始化的toyger实例
    //@param callback[nonnullable]:回调实例，该实例需要实现callback的所有接口
    //@param cb_receiver[nullable]:该参数会在回调时返回给调用方，调用方可以通过这个参数将接口调用实例和回调接受实例进行绑定，如果不需要绑定，这个参数可以为空
    //@param config[nonnullable]:活体、质量等协议参数
    void tg_config(void *tg_instance, ToygerCallback *callback, void *cb_receiver, const TGConfig &config);

    //[同步]处理图片帧
    //@param tg_instance[nonnullable]:init时初始化的toyger实例
    //@param frame[nonnullable]:图片数据
    //@return 目前恒为true
    bool tg_process_image(void *tg_instance, const TGFrame &frame);

    //[同步]清空算法缓存，比如在重试等场景应用
    //@param tg_instance[nonnullable]:init时初始化的toyger实例
    void tg_reset(void *tg_instance);

    //[同步]清空算法资源，模型、算法实例将被释放，在结束时调用
    //@param tg_instance[nonnullable]:init时初始化的toyger实例
    void tg_release(void *tg_instance);

#ifdef __cplusplus
}
#endif
