/**
 * Simply returns tensorflow library version through Node.js
 */
//int main() {
//  printf("Hello.... C library version is %s\n", TF_Version());
//  return 0;
//}


#include <node.h>
#include <tensorflow/c/c_api.h>

namespace add_func {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Version(const FunctionCallbackInfo<Value> & args) {
  Isolate *isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, TF_Version()));
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "version", Version);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}  // namespace add_func



