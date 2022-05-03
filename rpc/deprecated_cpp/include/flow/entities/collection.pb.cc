// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: flow/entities/collection.proto

#include "flow/entities/collection.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace flow {
namespace entities {
constexpr Collection::Collection(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : transaction_ids_()
  , id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct CollectionDefaultTypeInternal {
  constexpr CollectionDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~CollectionDefaultTypeInternal() {}
  union {
    Collection _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT CollectionDefaultTypeInternal _Collection_default_instance_;
constexpr CollectionGuarantee::CollectionGuarantee(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : signatures_()
  , signer_ids_()
  , collection_id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , reference_block_id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , signature_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct CollectionGuaranteeDefaultTypeInternal {
  constexpr CollectionGuaranteeDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~CollectionGuaranteeDefaultTypeInternal() {}
  union {
    CollectionGuarantee _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT CollectionGuaranteeDefaultTypeInternal _CollectionGuarantee_default_instance_;
}  // namespace entities
}  // namespace flow
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_flow_2fentities_2fcollection_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_flow_2fentities_2fcollection_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_flow_2fentities_2fcollection_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_flow_2fentities_2fcollection_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::flow::entities::Collection, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::flow::entities::Collection, id_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::Collection, transaction_ids_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::flow::entities::CollectionGuarantee, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::flow::entities::CollectionGuarantee, collection_id_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::CollectionGuarantee, signatures_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::CollectionGuarantee, reference_block_id_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::CollectionGuarantee, signature_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::CollectionGuarantee, signer_ids_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::flow::entities::Collection)},
  { 8, -1, -1, sizeof(::flow::entities::CollectionGuarantee)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::flow::entities::_Collection_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::flow::entities::_CollectionGuarantee_default_instance_),
};

const char descriptor_table_protodef_flow_2fentities_2fcollection_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\036flow/entities/collection.proto\022\rflow.e"
  "ntities\"1\n\nCollection\022\n\n\002id\030\001 \001(\014\022\027\n\017tra"
  "nsaction_ids\030\002 \003(\014\"\203\001\n\023CollectionGuarant"
  "ee\022\025\n\rcollection_id\030\001 \001(\014\022\022\n\nsignatures\030"
  "\002 \003(\014\022\032\n\022reference_block_id\030\003 \001(\014\022\021\n\tsig"
  "nature\030\004 \001(\014\022\022\n\nsigner_ids\030\005 \003(\014BP\n\034org."
  "onflow.protobuf.entitiesZ0github.com/onf"
  "low/flow/protobuf/go/flow/entitiesb\006prot"
  "o3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_flow_2fentities_2fcollection_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_flow_2fentities_2fcollection_2eproto = {
  false, false, 322, descriptor_table_protodef_flow_2fentities_2fcollection_2eproto, "flow/entities/collection.proto", 
  &descriptor_table_flow_2fentities_2fcollection_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_flow_2fentities_2fcollection_2eproto::offsets,
  file_level_metadata_flow_2fentities_2fcollection_2eproto, file_level_enum_descriptors_flow_2fentities_2fcollection_2eproto, file_level_service_descriptors_flow_2fentities_2fcollection_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_flow_2fentities_2fcollection_2eproto_getter() {
  return &descriptor_table_flow_2fentities_2fcollection_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_flow_2fentities_2fcollection_2eproto(&descriptor_table_flow_2fentities_2fcollection_2eproto);
namespace flow {
namespace entities {

// ===================================================================

class Collection::_Internal {
 public:
};

Collection::Collection(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  transaction_ids_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:flow.entities.Collection)
}
Collection::Collection(const Collection& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      transaction_ids_(from.transaction_ids_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_id().empty()) {
    id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_id(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:flow.entities.Collection)
}

void Collection::SharedCtor() {
id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

Collection::~Collection() {
  // @@protoc_insertion_point(destructor:flow.entities.Collection)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Collection::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Collection::ArenaDtor(void* object) {
  Collection* _this = reinterpret_cast< Collection* >(object);
  (void)_this;
}
void Collection::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Collection::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Collection::Clear() {
// @@protoc_insertion_point(message_clear_start:flow.entities.Collection)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  transaction_ids_.Clear();
  id_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Collection::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bytes id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated bytes transaction_ids = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_transaction_ids();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Collection::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:flow.entities.Collection)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes id = 1;
  if (!this->_internal_id().empty()) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_id(), target);
  }

  // repeated bytes transaction_ids = 2;
  for (int i = 0, n = this->_internal_transaction_ids_size(); i < n; i++) {
    const auto& s = this->_internal_transaction_ids(i);
    target = stream->WriteBytes(2, s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:flow.entities.Collection)
  return target;
}

size_t Collection::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:flow.entities.Collection)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated bytes transaction_ids = 2;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(transaction_ids_.size());
  for (int i = 0, n = transaction_ids_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
      transaction_ids_.Get(i));
  }

  // bytes id = 1;
  if (!this->_internal_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Collection::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Collection::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Collection::GetClassData() const { return &_class_data_; }

void Collection::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Collection *>(to)->MergeFrom(
      static_cast<const Collection &>(from));
}


void Collection::MergeFrom(const Collection& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:flow.entities.Collection)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  transaction_ids_.MergeFrom(from.transaction_ids_);
  if (!from._internal_id().empty()) {
    _internal_set_id(from._internal_id());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Collection::CopyFrom(const Collection& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:flow.entities.Collection)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Collection::IsInitialized() const {
  return true;
}

void Collection::InternalSwap(Collection* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  transaction_ids_.InternalSwap(&other->transaction_ids_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &id_, lhs_arena,
      &other->id_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata Collection::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_flow_2fentities_2fcollection_2eproto_getter, &descriptor_table_flow_2fentities_2fcollection_2eproto_once,
      file_level_metadata_flow_2fentities_2fcollection_2eproto[0]);
}

// ===================================================================

class CollectionGuarantee::_Internal {
 public:
};

CollectionGuarantee::CollectionGuarantee(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  signatures_(arena),
  signer_ids_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:flow.entities.CollectionGuarantee)
}
CollectionGuarantee::CollectionGuarantee(const CollectionGuarantee& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      signatures_(from.signatures_),
      signer_ids_(from.signer_ids_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  collection_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_collection_id().empty()) {
    collection_id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_collection_id(), 
      GetArenaForAllocation());
  }
  reference_block_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_reference_block_id().empty()) {
    reference_block_id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_reference_block_id(), 
      GetArenaForAllocation());
  }
  signature_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_signature().empty()) {
    signature_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_signature(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:flow.entities.CollectionGuarantee)
}

void CollectionGuarantee::SharedCtor() {
collection_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
reference_block_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
signature_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

CollectionGuarantee::~CollectionGuarantee() {
  // @@protoc_insertion_point(destructor:flow.entities.CollectionGuarantee)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void CollectionGuarantee::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  collection_id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  reference_block_id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  signature_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void CollectionGuarantee::ArenaDtor(void* object) {
  CollectionGuarantee* _this = reinterpret_cast< CollectionGuarantee* >(object);
  (void)_this;
}
void CollectionGuarantee::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void CollectionGuarantee::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void CollectionGuarantee::Clear() {
// @@protoc_insertion_point(message_clear_start:flow.entities.CollectionGuarantee)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  signatures_.Clear();
  signer_ids_.Clear();
  collection_id_.ClearToEmpty();
  reference_block_id_.ClearToEmpty();
  signature_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CollectionGuarantee::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bytes collection_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_collection_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated bytes signatures = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_signatures();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else
          goto handle_unusual;
        continue;
      // bytes reference_block_id = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_reference_block_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes signature = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_signature();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated bytes signer_ids = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_signer_ids();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<42>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* CollectionGuarantee::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:flow.entities.CollectionGuarantee)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes collection_id = 1;
  if (!this->_internal_collection_id().empty()) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_collection_id(), target);
  }

  // repeated bytes signatures = 2;
  for (int i = 0, n = this->_internal_signatures_size(); i < n; i++) {
    const auto& s = this->_internal_signatures(i);
    target = stream->WriteBytes(2, s, target);
  }

  // bytes reference_block_id = 3;
  if (!this->_internal_reference_block_id().empty()) {
    target = stream->WriteBytesMaybeAliased(
        3, this->_internal_reference_block_id(), target);
  }

  // bytes signature = 4;
  if (!this->_internal_signature().empty()) {
    target = stream->WriteBytesMaybeAliased(
        4, this->_internal_signature(), target);
  }

  // repeated bytes signer_ids = 5;
  for (int i = 0, n = this->_internal_signer_ids_size(); i < n; i++) {
    const auto& s = this->_internal_signer_ids(i);
    target = stream->WriteBytes(5, s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:flow.entities.CollectionGuarantee)
  return target;
}

size_t CollectionGuarantee::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:flow.entities.CollectionGuarantee)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated bytes signatures = 2;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(signatures_.size());
  for (int i = 0, n = signatures_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
      signatures_.Get(i));
  }

  // repeated bytes signer_ids = 5;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(signer_ids_.size());
  for (int i = 0, n = signer_ids_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
      signer_ids_.Get(i));
  }

  // bytes collection_id = 1;
  if (!this->_internal_collection_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_collection_id());
  }

  // bytes reference_block_id = 3;
  if (!this->_internal_reference_block_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_reference_block_id());
  }

  // bytes signature = 4;
  if (!this->_internal_signature().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_signature());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CollectionGuarantee::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    CollectionGuarantee::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CollectionGuarantee::GetClassData() const { return &_class_data_; }

void CollectionGuarantee::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<CollectionGuarantee *>(to)->MergeFrom(
      static_cast<const CollectionGuarantee &>(from));
}


void CollectionGuarantee::MergeFrom(const CollectionGuarantee& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:flow.entities.CollectionGuarantee)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  signatures_.MergeFrom(from.signatures_);
  signer_ids_.MergeFrom(from.signer_ids_);
  if (!from._internal_collection_id().empty()) {
    _internal_set_collection_id(from._internal_collection_id());
  }
  if (!from._internal_reference_block_id().empty()) {
    _internal_set_reference_block_id(from._internal_reference_block_id());
  }
  if (!from._internal_signature().empty()) {
    _internal_set_signature(from._internal_signature());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void CollectionGuarantee::CopyFrom(const CollectionGuarantee& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:flow.entities.CollectionGuarantee)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CollectionGuarantee::IsInitialized() const {
  return true;
}

void CollectionGuarantee::InternalSwap(CollectionGuarantee* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  signatures_.InternalSwap(&other->signatures_);
  signer_ids_.InternalSwap(&other->signer_ids_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &collection_id_, lhs_arena,
      &other->collection_id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &reference_block_id_, lhs_arena,
      &other->reference_block_id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &signature_, lhs_arena,
      &other->signature_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata CollectionGuarantee::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_flow_2fentities_2fcollection_2eproto_getter, &descriptor_table_flow_2fentities_2fcollection_2eproto_once,
      file_level_metadata_flow_2fentities_2fcollection_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace entities
}  // namespace flow
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::flow::entities::Collection* Arena::CreateMaybeMessage< ::flow::entities::Collection >(Arena* arena) {
  return Arena::CreateMessageInternal< ::flow::entities::Collection >(arena);
}
template<> PROTOBUF_NOINLINE ::flow::entities::CollectionGuarantee* Arena::CreateMaybeMessage< ::flow::entities::CollectionGuarantee >(Arena* arena) {
  return Arena::CreateMessageInternal< ::flow::entities::CollectionGuarantee >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
