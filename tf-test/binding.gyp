{
  "targets": [
    {
      "target_name": "tf_test",
      "sources": ["tf_test.cc"],
      "include_dirs": [
        "/usr/local/include"
      ],
      "libraries": [
        "/usr/local/lib/libtensorflow.so",
        "/usr/local/lib/libtensorflow_framework.so",
      ]
    }
  ]
}


