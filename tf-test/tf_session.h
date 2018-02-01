#ifndef TF_SESSION_H_
#define TF_SESSION_H_

#include <tensorflow/c/c_api.h>

class NodeTFSession {
public:
 NodeTFSession() {
 }

 ~NodeTFSession() {
   TF_DeleteGraph(mGraph);
   TF_DeleteStatus(mStatus);
   TF_DeleteSessionOptions(mSessionOptions);
   TF_CloseSession(mSession, mStatus);
   TF_DeleteSession(mSession, mStatus);
 }

 void Init() {
   mGraph = TF_NewGraph();
   mStatus = TF_NewStatus();
   mSessionOptions = TF_NewSessionOptions();
   mSession = TF_NewSession(mGraph, mSessionOptions, mStatus);
 }

 TF_Graph* GetGraph() {
   return mGraph;
 }

protected:
  TF_Graph* mGraph;
  TF_Session* mSession;
  TF_SessionOptions* mSessionOptions;
  TF_Status* mStatus;
};

#endif  // TF_SESSION_H_
