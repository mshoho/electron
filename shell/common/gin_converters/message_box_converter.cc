// Copyright (c) 2019 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "shell/common/gin_converters/message_box_converter.h"

#include "gin/dictionary.h"
#include "shell/common/gin_converters/image_converter_gin_adapter.h"

namespace gin {

bool Converter<electron::MessageBoxSettings>::FromV8(
    v8::Isolate* isolate,
    v8::Local<v8::Value> val,
    electron::MessageBoxSettings* out) {
  gin::Dictionary dict(nullptr);
  int type = 0;
  if (!ConvertFromV8(isolate, val, &dict))
    return false;
  dict.Get("window", &out->parent_window);
  dict.Get("messageBoxType", &type);
  out->type = static_cast<electron::MessageBoxType>(type);
  dict.Get("buttons", &out->buttons);
  dict.Get("defaultId", &out->default_id);
  dict.Get("cancelId", &out->cancel_id);
  dict.Get("options", &out->options);
  dict.Get("title", &out->title);
  dict.Get("message", &out->message);
  dict.Get("detail", &out->detail);
  dict.Get("checkboxLabel", &out->checkbox_label);
  dict.Get("checkboxChecked", &out->checkbox_checked);
  dict.Get("icon", &out->icon);
  return true;
}

}  // namespace gin
