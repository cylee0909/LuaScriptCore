//
// Created by 冯鸿杰 on 16/10/31.
//

#ifndef ANDROID_LUAPOINTER_H
#define ANDROID_LUAPOINTER_H

#include "LuaObject.h"
#include "LuaDefined.h"

namespace cn {
    namespace vimfung {
        namespace luascriptcore {
            
            class LuaObjectDecoder;
            class LuaObjectEncoder;

            /**
             * Lua的指针对象
             */
            class LuaPointer : public LuaObject
            {
            private:
                LuaUserdataRef _value;
                bool _needFree;

            public:
                LuaPointer ();
                LuaPointer (LuaUserdataRef userdata);
                LuaPointer (const void *value);
                ~LuaPointer();
                
                /**
                 * 初始化, 在反序列化对象时会触发该方法
                 *
                 * @param decoder 解码器
                 */
                LuaPointer (LuaObjectDecoder *decoder);
                
                /**
                 获取类型名称
                 
                 @return 类型名称
                 */
                virtual std::string typeName();
                
                /**
                 序列化对象
                 
                 @param encoder 编码器
                 */
                virtual void serialization (LuaObjectEncoder *encoder);

            public:

                /**
                 * 获取指针值
                 */
                const LuaUserdataRef getValue();
            };

        }
    }
}


#endif //ANDROID_LUAPOINTER_H
