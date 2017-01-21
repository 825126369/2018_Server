// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: db_protobuf_struct.proto

#ifndef PROTOBUF_db_5fprotobuf_5fstruct_2eproto__INCLUDED
#define PROTOBUF_db_5fprotobuf_5fstruct_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace db_protobuf {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_db_5fprotobuf_5fstruct_2eproto();
void protobuf_InitDefaults_db_5fprotobuf_5fstruct_2eproto();
void protobuf_AssignDesc_db_5fprotobuf_5fstruct_2eproto();
void protobuf_ShutdownFile_db_5fprotobuf_5fstruct_2eproto();

class serverinfo;

// ===================================================================

class serverinfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:db_protobuf.serverinfo) */ {
 public:
  serverinfo();
  virtual ~serverinfo();

  serverinfo(const serverinfo& from);

  inline serverinfo& operator=(const serverinfo& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const serverinfo& default_instance();

  static const serverinfo* internal_default_instance();

  void Swap(serverinfo* other);

  // implements Message ----------------------------------------------

  inline serverinfo* New() const { return New(NULL); }

  serverinfo* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const serverinfo& from);
  void MergeFrom(const serverinfo& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(serverinfo* other);
  void UnsafeMergeFrom(const serverinfo& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint64 serverId = 1;
  void clear_serverid();
  static const int kServerIdFieldNumber = 1;
  ::google::protobuf::uint64 serverid() const;
  void set_serverid(::google::protobuf::uint64 value);

  // repeated uint64 roleId = 2;
  int roleid_size() const;
  void clear_roleid();
  static const int kRoleIdFieldNumber = 2;
  ::google::protobuf::uint64 roleid(int index) const;
  void set_roleid(int index, ::google::protobuf::uint64 value);
  void add_roleid(::google::protobuf::uint64 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
      roleid() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
      mutable_roleid();

  // optional uint64 lastLoginRoleId = 3;
  void clear_lastloginroleid();
  static const int kLastLoginRoleIdFieldNumber = 3;
  ::google::protobuf::uint64 lastloginroleid() const;
  void set_lastloginroleid(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:db_protobuf.serverinfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint64 > roleid_;
  mutable int _roleid_cached_byte_size_;
  ::google::protobuf::uint64 serverid_;
  ::google::protobuf::uint64 lastloginroleid_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_db_5fprotobuf_5fstruct_2eproto_impl();
  friend void  protobuf_AddDesc_db_5fprotobuf_5fstruct_2eproto_impl();
  friend void protobuf_AssignDesc_db_5fprotobuf_5fstruct_2eproto();
  friend void protobuf_ShutdownFile_db_5fprotobuf_5fstruct_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<serverinfo> serverinfo_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// serverinfo

// optional uint64 serverId = 1;
inline void serverinfo::clear_serverid() {
  serverid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 serverinfo::serverid() const {
  // @@protoc_insertion_point(field_get:db_protobuf.serverinfo.serverId)
  return serverid_;
}
inline void serverinfo::set_serverid(::google::protobuf::uint64 value) {
  
  serverid_ = value;
  // @@protoc_insertion_point(field_set:db_protobuf.serverinfo.serverId)
}

// repeated uint64 roleId = 2;
inline int serverinfo::roleid_size() const {
  return roleid_.size();
}
inline void serverinfo::clear_roleid() {
  roleid_.Clear();
}
inline ::google::protobuf::uint64 serverinfo::roleid(int index) const {
  // @@protoc_insertion_point(field_get:db_protobuf.serverinfo.roleId)
  return roleid_.Get(index);
}
inline void serverinfo::set_roleid(int index, ::google::protobuf::uint64 value) {
  roleid_.Set(index, value);
  // @@protoc_insertion_point(field_set:db_protobuf.serverinfo.roleId)
}
inline void serverinfo::add_roleid(::google::protobuf::uint64 value) {
  roleid_.Add(value);
  // @@protoc_insertion_point(field_add:db_protobuf.serverinfo.roleId)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
serverinfo::roleid() const {
  // @@protoc_insertion_point(field_list:db_protobuf.serverinfo.roleId)
  return roleid_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
serverinfo::mutable_roleid() {
  // @@protoc_insertion_point(field_mutable_list:db_protobuf.serverinfo.roleId)
  return &roleid_;
}

// optional uint64 lastLoginRoleId = 3;
inline void serverinfo::clear_lastloginroleid() {
  lastloginroleid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 serverinfo::lastloginroleid() const {
  // @@protoc_insertion_point(field_get:db_protobuf.serverinfo.lastLoginRoleId)
  return lastloginroleid_;
}
inline void serverinfo::set_lastloginroleid(::google::protobuf::uint64 value) {
  
  lastloginroleid_ = value;
  // @@protoc_insertion_point(field_set:db_protobuf.serverinfo.lastLoginRoleId)
}

inline const serverinfo* serverinfo::internal_default_instance() {
  return &serverinfo_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace db_protobuf

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_db_5fprotobuf_5fstruct_2eproto__INCLUDED
