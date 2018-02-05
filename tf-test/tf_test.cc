#include <cstring>
#include <node.h>
#include <tensorflow/c/c_api.h>
#include "eager/c_api.h"
#include "tf_session.h"

namespace add_func {

void Version(const v8::FunctionCallbackInfo<v8::Value> & args) {
  v8::Isolate *isolate = args.GetIsolate();
  args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, TF_Version()));
}

void Deallocator(void* data, size_t, void* arg) {
  // TODO(kreeger): Actually do this - yes?
}

TF_Tensor* New_TFv8Tensor(v8::Handle<v8::Float32Array> array) {
  // Copy the v8 array to the TF array
  int64_t shape[] = {array->Length()};
  const int numBytes = array->Length() * sizeof(float);
  bool deallocator_called = false;

  auto data = array->Buffer()->GetContents().Data();

  // TODO - eventually move this into a wrapper.
  TF_Tensor* t = TF_AllocateTensor(TF_FLOAT, shape, 1, numBytes);
  memcpy(TF_TensorData(t), data, TF_TensorByteSize(t));

  return t;
}

void ArrayTest(const v8::FunctionCallbackInfo<v8::Value> & args) {
  NodeTFSession *session = new NodeTFSession();
  session->Init();

  /* ArrayBuffer buffer = args[0]->ArrayBuffer(); */
  v8::Isolate *isolate = args.GetIsolate();

  v8::Handle<v8::Value> v1 = args[0];
  v8::Handle<v8::Value> v2 = args[1];
  if (v2->IsFloat32Array() && v2->IsFloat32Array()) {
    // First, point v8 buffers to a new tensor
    TF_Tensor* left = New_TFv8Tensor(v8::Handle<v8::Float32Array>::Cast(v1));
    TF_Tensor* right = New_TFv8Tensor(v8::Handle<v8::Float32Array>::Cast(v2));

    printf("left tensor byte size  : %d\n", TF_TensorByteSize(left));
    printf("right tensor byte size : %d\n", TF_TensorByteSize(left));

    // Use context class.
    TF_Status* status = TF_NewStatus();
    TFE_TensorHandle* th = TFE_NewTensorHandle(left, status);
    printf("status: %d\n", TF_GetCode(status));

    //
    // TODO(kreeger): Left off right here.  Need to use TFE to call an op.
    //

    // Next, add an add operation to the graph
    TF_OperationDescription* desc = TF_NewOperation(session->GetGraph(), "AddN", "test");

    double value = 0.0;

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

