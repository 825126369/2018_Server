// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: db_protobuf.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "db_protobuf.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace db_protobuf {

namespace {

const ::google::protobuf::Descriptor* db_loginallserverinfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  db_loginallserverinfo_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_db_5fprotobuf_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_db_5fprotobuf_2eproto() {
  protobuf_AddDesc_db_5fprotobuf_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "db_protobuf.proto");
  GOOGLE_CHECK(file != NULL);
  db_loginallserverinfo_descriptor_ = file->message_type(0);
  static const int db_loginallserverinfo_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(db_loginallserverinfo, allserverinfo_),
  };
  db_loginallserverinfo_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      db_loginallserverinfo_descriptor_,
      db_loginallserverinfo::internal_default_instance(),
      db_loginallserverinfo_offsets_,
      -1,
      -1,
      -1,
      sizeof(db_loginallserverinfo),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(db_loginallserverinfo, _internal_metadata_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_db_5fprotobuf_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      db_loginallserverinfo_descriptor_, db_loginallserverinfo::internal_default_instance());
}

}  // namespace

void protobuf_ShutdownFile_db_5fprotobuf_2eproto() {
  db_loginallserverinfo_default_instance_.Shutdown();
  delete db_loginallserverinfo_reflection_;
}

void protobuf_InitDefaults_db_5fprotobuf_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::db_protobuf::protobuf_InitDefaults_db_5fprotobuf_5fstruct_2eproto();
  db_loginallserverinfo_default_instance_.DefaultConstruct();
  db_loginallserverinfo_default_instance_.get_mutable()->InitAsDefaultInstance();
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_InitDefaults_db_5fprotobuf_2eproto_once_);
void protobuf_InitDefaults_db_5fprotobuf_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_InitDefaults_db_5fprotobuf_2eproto_once_,
                 &protobuf_InitDefaults_db_5fprotobuf_2eproto_impl);
}
void protobuf_AddDesc_db_5fprotobuf_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  protobuf_InitDefaults_db_5fprotobuf_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021db_protobuf.proto\022\013db_protobuf\032\030db_pro"
    "tobuf_struct.proto\"G\n\025db_loginallserveri"
    "nfo\022.\n\rallserverinfo\030\001 \003(\0132\027.db_protobuf"
    ".serverinfob\006proto3", 139);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "db_protobuf.proto", &protobuf_RegisterTypes);
  ::db_protobuf::protobuf_AddDesc_db_5fprotobuf_5fstruct_2eproto();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_db_5fprotobuf_2eproto);
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_db_5fprotobuf_2eproto_once_);
void protobuf_AddDesc_db_5fprotobuf_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_db_5fprotobuf_2eproto_once_,
                 &protobuf_AddDesc_db_5fprotobuf_2eproto_impl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_db_5fprotobuf_2eproto {
  StaticDescriptorInitializer_db_5fprotobuf_2eproto() {
    protobuf_AddDesc_db_5fprotobuf_2eproto();
  }
} static_descriptor_initializer_db_5fprotobuf_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD GOOGLE_ATTRIBUTE_NORETURN;
static void MergeFromFail(int line) {
  ::google::protobuf::internal::MergeFromFail(__FILE__, line);
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int db_loginallserverinfo::kAllserverinfoFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

db_loginallserverinfo::db_loginallserverinfo()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (this != internal_default_instance()) protobuf_InitDefaults_db_5fprotobuf_2eproto();
  SharedCtor();
  // @@protoc_insertion_point(constructor:db_protobuf.db_loginallserverinfo)
}

void db_loginallserverinfo::InitAsDefaultInstance() {
}

db_loginallserverinfo::db_loginallserverinfo(const db_loginallserverinfo& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  UnsafeMergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:db_protobuf.db_loginallserverinfo)
}

void db_loginallserverinfo::SharedCtor() {
  _cached_size_ = 0;
}

db_loginallserverinfo::~db_loginallserverinfo() {
  // @@protoc_insertion_point(destructor:db_protobuf.db_loginallserverinfo)
  SharedDtor();
}

void db_loginallserverinfo::SharedDtor() {
}

void db_loginallserverinfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* db_loginallserverinfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return db_loginallserverinfo_descriptor_;
}

const db_loginallserverinfo& db_loginallserverinfo::default_instance() {
  protobuf_InitDefaults_db_5fprotobuf_2eproto();
  return *internal_default_instance();
}

::google::protobuf::internal::ExplicitlyConstructed<db_loginallserverinfo> db_loginallserverinfo_default_instance_;

db_loginallserverinfo* db_loginallserverinfo::New(::google::protobuf::Arena* arena) const {
  db_loginallserverinfo* n = new db_loginallserverinfo;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void db_loginallserverinfo::Clear() {
// @@protoc_insertion_point(message_clear_start:db_protobuf.db_loginallserverinfo)
  allserverinfo_.Clear();
}

bool db_loginallserverinfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:db_protobuf.db_loginallserverinfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .db_protobuf.serverinfo allserverinfo = 1;
      case 1: {
        if (tag == 10) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_allserverinfo:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_allserverinfo()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_loop_allserverinfo;
        input->UnsafeDecrementRecursionDepth();
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:db_protobuf.db_loginallserverinfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:db_protobuf.db_loginallserverinfo)
  return false;
#undef DO_
}

void db_loginallserverinfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:db_protobuf.db_loginallserverinfo)
  // repeated .db_protobuf.serverinfo allserverinfo = 1;
  for (unsigned int i = 0, n = this->allserverinfo_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->allserverinfo(i), output);
  }

  // @@protoc_insertion_point(serialize_end:db_protobuf.db_loginallserverinfo)
}

::google::protobuf::uint8* db_loginallserverinfo::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:db_protobuf.db_loginallserverinfo)
  // repeated .db_protobuf.serverinfo allserverinfo = 1;
  for (unsigned int i = 0, n = this->allserverinfo_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, this->allserverinfo(i), false, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:db_protobuf.db_loginallserverinfo)
  return target;
}

size_t db_loginallserverinfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:db_protobuf.db_loginallserverinfo)
  size_t total_size = 0;

  // repeated .db_protobuf.serverinfo allserverinfo = 1;
  {
    unsigned int count = this->allserverinfo_size();
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->allserverinfo(i));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void db_loginallserverinfo::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:db_protobuf.db_loginallserverinfo)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const db_loginallserverinfo* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const db_loginallserverinfo>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:db_protobuf.db_loginallserverinfo)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:db_protobuf.db_loginallserverinfo)
    UnsafeMergeFrom(*source);
  }
}

void db_loginallserverinfo::MergeFrom(const db_loginallserverinfo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:db_protobuf.db_loginallserverinfo)
  if (GOOGLE_PREDICT_TRUE(&from != this)) {
    UnsafeMergeFrom(from);
  } else {
    MergeFromFail(__LINE__);
  }
}

void db_loginallserverinfo::UnsafeMergeFrom(const db_loginallserverinfo& from) {
  GOOGLE_DCHECK(&from != this);
  allserverinfo_.MergeFrom(from.allserverinfo_);
}

void db_loginallserverinfo::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:db_protobuf.db_loginallserverinfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void db_loginallserverinfo::CopyFrom(const db_loginallserverinfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:db_protobuf.db_loginallserverinfo)
  if (&from == this) return;
  Clear();
  UnsafeMergeFrom(from);
}

bool db_loginallserverinfo::IsInitialized() const {

  return true;
}

void db_loginallserverinfo::Swap(db_loginallserverinfo* other) {
  if (other == this) return;
  InternalSwap(other);
}
void db_loginallserverinfo::InternalSwap(db_loginallserverinfo* other) {
  allserverinfo_.UnsafeArenaSwap(&other->allserverinfo_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata db_loginallserverinfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = db_loginallserverinfo_descriptor_;
  metadata.reflection = db_loginallserverinfo_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// db_loginallserverinfo

// repeated .db_protobuf.serverinfo allserverinfo = 1;
int db_loginallserverinfo::allserverinfo_size() const {
  return allserverinfo_.size();
}
void db_loginallserverinfo::clear_allserverinfo() {
  allserverinfo_.Clear();
}
const ::db_protobuf::serverinfo& db_loginallserverinfo::allserverinfo(int index) const {
  // @@protoc_insertion_point(field_get:db_protobuf.db_loginallserverinfo.allserverinfo)
  return allserverinfo_.Get(index);
}
::db_protobuf::serverinfo* db_loginallserverinfo::mutable_allserverinfo(int index) {
  // @@protoc_insertion_point(field_mutable:db_protobuf.db_loginallserverinfo.allserverinfo)
  return allserverinfo_.Mutable(index);
}
::db_protobuf::serverinfo* db_loginallserverinfo::add_allserverinfo() {
  // @@protoc_insertion_point(field_add:db_protobuf.db_loginallserverinfo.allserverinfo)
  return allserverinfo_.Add();
}
::google::protobuf::RepeatedPtrField< ::db_protobuf::serverinfo >*
db_loginallserverinfo::mutable_allserverinfo() {
  // @@protoc_insertion_point(field_mutable_list:db_protobuf.db_loginallserverinfo.allserverinfo)
  return &allserverinfo_;
}
const ::google::protobuf::RepeatedPtrField< ::db_protobuf::serverinfo >&
db_loginallserverinfo::allserverinfo() const {
  // @@protoc_insertion_point(field_list:db_protobuf.db_loginallserverinfo.allserverinfo)
  return allserverinfo_;
}

inline const db_loginallserverinfo* db_loginallserverinfo::internal_default_instance() {
  return &db_loginallserverinfo_default_instance_.get();
}
#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace db_protobuf

// @@protoc_insertion_point(global_scope)
