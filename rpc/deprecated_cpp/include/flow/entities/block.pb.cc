// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: flow/entities/block.proto

#include "flow/entities/block.pb.h"

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
constexpr Block::Block(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : collection_guarantees_()
  , block_seals_()
  , signatures_()
  , execution_receipt_metalist_()
  , execution_result_list_()
  , id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , parent_id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , timestamp_(nullptr)
  , height_(uint64_t{0u}){}
struct BlockDefaultTypeInternal {
  constexpr BlockDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~BlockDefaultTypeInternal() {}
  union {
    Block _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT BlockDefaultTypeInternal _Block_default_instance_;
}  // namespace entities
}  // namespace flow
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_flow_2fentities_2fblock_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_flow_2fentities_2fblock_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_flow_2fentities_2fblock_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_flow_2fentities_2fblock_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::flow::entities::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::flow::entities::Block, id_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::Block, parent_id_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::Block, height_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::Block, timestamp_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::Block, collection_guarantees_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::Block, block_seals_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::Block, signatures_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::Block, execution_receipt_metalist_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::Block, execution_result_list_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::flow::entities::Block)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::flow::entities::_Block_default_instance_),
};

const char descriptor_table_protodef_flow_2fentities_2fblock_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\031flow/entities/block.proto\022\rflow.entiti"
  "es\032\037google/protobuf/timestamp.proto\032\036flo"
  "w/entities/collection.proto\032\036flow/entiti"
  "es/block_seal.proto\032$flow/entities/execu"
  "tion_result.proto\"\363\002\n\005Block\022\n\n\002id\030\001 \001(\014\022"
  "\021\n\tparent_id\030\002 \001(\014\022\016\n\006height\030\003 \001(\004\022-\n\tti"
  "mestamp\030\004 \001(\0132\032.google.protobuf.Timestam"
  "p\022A\n\025collection_guarantees\030\005 \003(\0132\".flow."
  "entities.CollectionGuarantee\022-\n\013block_se"
  "als\030\006 \003(\0132\030.flow.entities.BlockSeal\022\022\n\ns"
  "ignatures\030\007 \003(\014\022G\n\032execution_receipt_met"
  "aList\030\010 \003(\0132#.flow.entities.ExecutionRec"
  "eiptMeta\022=\n\025execution_result_list\030\t \003(\0132"
  "\036.flow.entities.ExecutionResultBP\n\034org.o"
  "nflow.protobuf.entitiesZ0github.com/onfl"
  "ow/flow/protobuf/go/flow/entitiesb\006proto"
  "3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_flow_2fentities_2fblock_2eproto_deps[4] = {
  &::descriptor_table_flow_2fentities_2fblock_5fseal_2eproto,
  &::descriptor_table_flow_2fentities_2fcollection_2eproto,
  &::descriptor_table_flow_2fentities_2fexecution_5fresult_2eproto,
  &::descriptor_table_google_2fprotobuf_2ftimestamp_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_flow_2fentities_2fblock_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_flow_2fentities_2fblock_2eproto = {
  false, false, 641, descriptor_table_protodef_flow_2fentities_2fblock_2eproto, "flow/entities/block.proto", 
  &descriptor_table_flow_2fentities_2fblock_2eproto_once, descriptor_table_flow_2fentities_2fblock_2eproto_deps, 4, 1,
  schemas, file_default_instances, TableStruct_flow_2fentities_2fblock_2eproto::offsets,
  file_level_metadata_flow_2fentities_2fblock_2eproto, file_level_enum_descriptors_flow_2fentities_2fblock_2eproto, file_level_service_descriptors_flow_2fentities_2fblock_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_flow_2fentities_2fblock_2eproto_getter() {
  return &descriptor_table_flow_2fentities_2fblock_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_flow_2fentities_2fblock_2eproto(&descriptor_table_flow_2fentities_2fblock_2eproto);
namespace flow {
namespace entities {

// ===================================================================

class Block::_Internal {
 public:
  static const ::PROTOBUF_NAMESPACE_ID::Timestamp& timestamp(const Block* msg);
};

const ::PROTOBUF_NAMESPACE_ID::Timestamp&
Block::_Internal::timestamp(const Block* msg) {
  return *msg->timestamp_;
}
void Block::clear_timestamp() {
  if (GetArenaForAllocation() == nullptr && timestamp_ != nullptr) {
    delete timestamp_;
  }
  timestamp_ = nullptr;
}
void Block::clear_collection_guarantees() {
  collection_guarantees_.Clear();
}
void Block::clear_block_seals() {
  block_seals_.Clear();
}
void Block::clear_execution_receipt_metalist() {
  execution_receipt_metalist_.Clear();
}
void Block::clear_execution_result_list() {
  execution_result_list_.Clear();
}
Block::Block(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  collection_guarantees_(arena),
  block_seals_(arena),
  signatures_(arena),
  execution_receipt_metalist_(arena),
  execution_result_list_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:flow.entities.Block)
}
Block::Block(const Block& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      collection_guarantees_(from.collection_guarantees_),
      block_seals_(from.block_seals_),
      signatures_(from.signatures_),
      execution_receipt_metalist_(from.execution_receipt_metalist_),
      execution_result_list_(from.execution_result_list_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_id().empty()) {
    id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_id(), 
      GetArenaForAllocation());
  }
  parent_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_parent_id().empty()) {
    parent_id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_parent_id(), 
      GetArenaForAllocation());
  }
  if (from._internal_has_timestamp()) {
    timestamp_ = new ::PROTOBUF_NAMESPACE_ID::Timestamp(*from.timestamp_);
  } else {
    timestamp_ = nullptr;
  }
  height_ = from.height_;
  // @@protoc_insertion_point(copy_constructor:flow.entities.Block)
}

void Block::SharedCtor() {
id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
parent_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&timestamp_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&height_) -
    reinterpret_cast<char*>(&timestamp_)) + sizeof(height_));
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:flow.entities.Block)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Block::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  parent_id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete timestamp_;
}

void Block::ArenaDtor(void* object) {
  Block* _this = reinterpret_cast< Block* >(object);
  (void)_this;
}
void Block::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:flow.entities.Block)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  collection_guarantees_.Clear();
  block_seals_.Clear();
  signatures_.Clear();
  execution_receipt_metalist_.Clear();
  execution_result_list_.Clear();
  id_.ClearToEmpty();
  parent_id_.ClearToEmpty();
  if (GetArenaForAllocation() == nullptr && timestamp_ != nullptr) {
    delete timestamp_;
  }
  timestamp_ = nullptr;
  height_ = uint64_t{0u};
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Block::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
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
      // bytes parent_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_parent_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint64 height = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          height_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .google.protobuf.Timestamp timestamp = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ctx->ParseMessage(_internal_mutable_timestamp(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .flow.entities.CollectionGuarantee collection_guarantees = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_collection_guarantees(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<42>(ptr));
        } else
          goto handle_unusual;
        continue;
      // repeated .flow.entities.BlockSeal block_seals = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_block_seals(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<50>(ptr));
        } else
          goto handle_unusual;
        continue;
      // repeated bytes signatures = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 58)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_signatures();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<58>(ptr));
        } else
          goto handle_unusual;
        continue;
      // repeated .flow.entities.ExecutionReceiptMeta execution_receipt_metaList = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 66)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_execution_receipt_metalist(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<66>(ptr));
        } else
          goto handle_unusual;
        continue;
      // repeated .flow.entities.ExecutionResult execution_result_list = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 74)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_execution_result_list(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<74>(ptr));
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

::PROTOBUF_NAMESPACE_ID::uint8* Block::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:flow.entities.Block)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes id = 1;
  if (!this->_internal_id().empty()) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_id(), target);
  }

  // bytes parent_id = 2;
  if (!this->_internal_parent_id().empty()) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_parent_id(), target);
  }

  // uint64 height = 3;
  if (this->_internal_height() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(3, this->_internal_height(), target);
  }

  // .google.protobuf.Timestamp timestamp = 4;
  if (this->_internal_has_timestamp()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        4, _Internal::timestamp(this), target, stream);
  }

  // repeated .flow.entities.CollectionGuarantee collection_guarantees = 5;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_collection_guarantees_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(5, this->_internal_collection_guarantees(i), target, stream);
  }

  // repeated .flow.entities.BlockSeal block_seals = 6;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_block_seals_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(6, this->_internal_block_seals(i), target, stream);
  }

  // repeated bytes signatures = 7;
  for (int i = 0, n = this->_internal_signatures_size(); i < n; i++) {
    const auto& s = this->_internal_signatures(i);
    target = stream->WriteBytes(7, s, target);
  }

  // repeated .flow.entities.ExecutionReceiptMeta execution_receipt_metaList = 8;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_execution_receipt_metalist_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(8, this->_internal_execution_receipt_metalist(i), target, stream);
  }

  // repeated .flow.entities.ExecutionResult execution_result_list = 9;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_execution_result_list_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(9, this->_internal_execution_result_list(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:flow.entities.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:flow.entities.Block)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .flow.entities.CollectionGuarantee collection_guarantees = 5;
  total_size += 1UL * this->_internal_collection_guarantees_size();
  for (const auto& msg : this->collection_guarantees_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .flow.entities.BlockSeal block_seals = 6;
  total_size += 1UL * this->_internal_block_seals_size();
  for (const auto& msg : this->block_seals_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated bytes signatures = 7;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(signatures_.size());
  for (int i = 0, n = signatures_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
      signatures_.Get(i));
  }

  // repeated .flow.entities.ExecutionReceiptMeta execution_receipt_metaList = 8;
  total_size += 1UL * this->_internal_execution_receipt_metalist_size();
  for (const auto& msg : this->execution_receipt_metalist_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .flow.entities.ExecutionResult execution_result_list = 9;
  total_size += 1UL * this->_internal_execution_result_list_size();
  for (const auto& msg : this->execution_result_list_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // bytes id = 1;
  if (!this->_internal_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_id());
  }

  // bytes parent_id = 2;
  if (!this->_internal_parent_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_parent_id());
  }

  // .google.protobuf.Timestamp timestamp = 4;
  if (this->_internal_has_timestamp()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *timestamp_);
  }

  // uint64 height = 3;
  if (this->_internal_height() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64SizePlusOne(this->_internal_height());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Block::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Block::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Block::GetClassData() const { return &_class_data_; }

void Block::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Block *>(to)->MergeFrom(
      static_cast<const Block &>(from));
}


void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:flow.entities.Block)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  collection_guarantees_.MergeFrom(from.collection_guarantees_);
  block_seals_.MergeFrom(from.block_seals_);
  signatures_.MergeFrom(from.signatures_);
  execution_receipt_metalist_.MergeFrom(from.execution_receipt_metalist_);
  execution_result_list_.MergeFrom(from.execution_result_list_);
  if (!from._internal_id().empty()) {
    _internal_set_id(from._internal_id());
  }
  if (!from._internal_parent_id().empty()) {
    _internal_set_parent_id(from._internal_parent_id());
  }
  if (from._internal_has_timestamp()) {
    _internal_mutable_timestamp()->::PROTOBUF_NAMESPACE_ID::Timestamp::MergeFrom(from._internal_timestamp());
  }
  if (from._internal_height() != 0) {
    _internal_set_height(from._internal_height());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:flow.entities.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Block::IsInitialized() const {
  return true;
}

void Block::InternalSwap(Block* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  collection_guarantees_.InternalSwap(&other->collection_guarantees_);
  block_seals_.InternalSwap(&other->block_seals_);
  signatures_.InternalSwap(&other->signatures_);
  execution_receipt_metalist_.InternalSwap(&other->execution_receipt_metalist_);
  execution_result_list_.InternalSwap(&other->execution_result_list_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &id_, lhs_arena,
      &other->id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &parent_id_, lhs_arena,
      &other->parent_id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Block, height_)
      + sizeof(Block::height_)
      - PROTOBUF_FIELD_OFFSET(Block, timestamp_)>(
          reinterpret_cast<char*>(&timestamp_),
          reinterpret_cast<char*>(&other->timestamp_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Block::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_flow_2fentities_2fblock_2eproto_getter, &descriptor_table_flow_2fentities_2fblock_2eproto_once,
      file_level_metadata_flow_2fentities_2fblock_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace entities
}  // namespace flow
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::flow::entities::Block* Arena::CreateMaybeMessage< ::flow::entities::Block >(Arena* arena) {
  return Arena::CreateMessageInternal< ::flow::entities::Block >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>