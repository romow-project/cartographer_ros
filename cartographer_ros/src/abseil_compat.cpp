// Compatibility shim for old abseil symbols that cartographer expects
// This provides stub implementations of abseil symbols that older versions of
// cartographer may have been compiled with, allowing them to work with newer
// versions of abseil.

extern "C" {
  // Stub for absl::Mutex::Dtor() - does nothing since we use std::mutex instead
  void _ZN4absl12lts_202505125Mutex4DtorEv() {}
}
