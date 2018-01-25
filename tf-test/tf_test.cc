#include <node.h>
#include <tensorflow/c/c_api.h>

namespace add_func {

void Version(const v8::FunctionCallbackInfo<v8::Value> & args) {
  v8::Isolate *isolate = args.GetIsolate();
  args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, TF_Version()));
}

void ArrayTest(const v8::FunctionCallbackInfo<v8::Value> & args) {
  /* ArrayBuffer buffer = args[0]->ArrayBuffer(); */
  v8::Isolate *isolate = args.GetIsolate();

  v8::Handle<v8::Value> v = args[0];
  if (v->IsFloat32Array()) {

    // TODO(kreeger): Left off right here.
    // Simply try and convert float32 to a simple tensor and add.
    // TF_Status* s = TF_NewStatus();
    // TF_Graph* graph = TF_NewGraph();

    double value = 0.0;
    v8::Handle<v8::Float32Array> array = v8::Handle<v8::Float32Array>::Cast(v);
    for (size_t i = 0; i < array->Length(); i++) {
      value += array->Get(i)->NumberValue();
    }

    args.GetReturnValue().Set(v8::Number::New(isolate, value));
  } else {
    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "Not a valid type"));
  }
}

void Init(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "version", Version);
  NODE_SET_METHOD(exports, "array_test", ArrayTest);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}  // namespace add_func

