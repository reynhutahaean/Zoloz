//
//  ZLZPbCallbacks.h
//  pbTest
//
//  Created by vincentbao on 2019/7/30.
//  Copyright © 2019 vincentbao. All rights reserved.
//

#ifndef callbacks_h
#define callbacks_h

#include <stdio.h>
#include <stdlib.h>
#include "zlz_pb_common.h"
#include "zlz_pb_encode.h"
#include "zlz_pb_decode.h"
#include "ZLZProtoBuf.pb.h"

class repeatedHandler {
public:
    uint32_t capacity;
    uint32_t count;
    
    repeatedHandler();
    
    ~repeatedHandler();
    
    void** callbackArray;
    
    void setCapacity(uint32_t cap);
    
    void addItem(void* callback);
    
    void* getItemPtrByIdx(uint32_t idx);
};

typedef struct rawBytesEncoder {
    const pb_field_t *field;
    const void* arg;
    size_t length;
}rawBytesEncoder;

void initRawBytesEncoder(rawBytesEncoder* encoder, const pb_field_t* field, const void* arg, size_t length);

// encode callbacks
bool encode_bytes(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);

bool encode_zlz_array(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);

bool encodeRawBytesWithField(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);

// decode callbacks
bool decode_string(pb_istream_t *stream, const pb_field_t *field, void **arg);

bool decode_array(pb_istream_t *stream, const pb_field_t *field, void **arg);

bool decode_bytes(pb_istream_t *stream, const pb_field_t *field, void **arg);

#endif /* callbacks_h */
