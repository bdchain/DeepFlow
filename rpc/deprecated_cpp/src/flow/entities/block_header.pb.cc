// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: flow/entities/block_header.proto

#include "flow/entities/block_header.pb.h"

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
constexpr BlockHeader::BlockHeader(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : parent_voter_ids_()
  , id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , parent_id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , payload_hash_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , parent_voter_sig_data_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , proposer_id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , proposer_sig_data_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , chain_id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , timestamp_(nullptr)
  , height_(uint64_t{0u})
  , view_(uint64_t{0u}){}
struct BlockHeaderDefaultTypeInternal {
  constexpr BlockHeaderDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~BlockHeaderDefaultTypeInternal() {}
  union {
    BlockHeader _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT BlockHeaderDefaultTypeInternal _BlockHeader_default_instance_;
}  // namespace entities
}  // namespace flow
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_flow_2fentities_2fblock_5fheader_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_flow_2fentities_2fblock_5fheader_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_flow_2fentities_2fblock_5fheader_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_flow_2fentities_2fblock_5fheader_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::flow::entities::BlockHeader, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::flow::entities::BlockHeader, id_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::BlockHeader, parent_id_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::BlockHeader, height_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::BlockHeader, timestamp_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::BlockHeader, payload_hash_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::BlockHeader, view_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::BlockHeader, parent_voter_ids_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::BlockHeader, parent_voter_sig_data_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::BlockHeader, proposer_id_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::BlockHeader, proposer_sig_data_),
  PROTOBUF_FIELD_OFFSET(::flow::entities::BlockHeader, chain_id_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::flow::entities::BlockHeader)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::flow::entities::_BlockHeader_default_instance_),
};

const char descriptor_table_protodef_flow_2fentities_2fblock_5fheader_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n flow/entities/block_header.proto\022\rflow"
  ".entities\032\037google/protobuf/timestamp.pro"
  "to\"\212\002\n\013BlockHeader\022\n\n\002id\030\001 \001(\014\022\021\n\tparent"
  "_id\030\002 \001(\014\022\016\n\006height\030\003 \001(\004\022-\n\ttimestamp\030\004"
  " \001(\0132\032.google.protobuf.Timestamp\022\024\n\014payl"
  "oad_hash\030\005 \001(\014\022\014\n\004view\030\006 \001(\004\022\030\n\020parent_v"
  "oter_ids\030\007 \003(\014\022\035\n\025parent_voter_sig_data\030"
  "\010 \001(\014\022\023\n\013proposer_id\030\t \001(\014\022\031\n\021proposer_s"
  "ig_data\030\n \001(\014\022\020\n\010chain_id\030\013 \001(\tBP\n\034org.o"
  "nflow.protobuf.entitiesZ0github.com/onfl"
  "ow/flow/protobuf/go/flow/entitiesb\006proto"
  "3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_flow_2fentities_2fblock_5fheader_2eproto_deps[1] = {
  &::descriptor_table_google_2fprotobuf_2ftimestamp_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_flow_2fentities_2fblock_5fheader_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_flow_2fentities_2fblock_5fheader_2eproto = {
  false, false, 441, descriptor_table_protodef_flow_2fentities_2fblock_5fheader_2eproto, "flow/entities/block_header.proto", 
  &descriptor_table_flow_2fentities_2fblock_5fheader_2eproto_once, descriptor_table_flow_2fentities_2fblock_5fheader_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_flow_2fentities_2fblock_5fheader_2eproto::offsets,
  file_level_metadata_flow_2fentities_2fblock_5fheader_2eproto, file_level_enum_descriptors_flow_2fentities_2fblock_5fheader_2eproto, file_level_service_descriptors_flow_2fentities_2fblock_5fheader_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_flow_2fentities_2fblock_5fheader_2eproto_getter() {
  return &descriptor_table_flow_2fentities_2fblock_5fheader_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_flow_2fentities_2fblock_5fheader_2eproto(&descriptor_table_flow_2fentities_2fblock_5fheader_2eproto);
namespace flow {
namespace entities {

// ===================================================================

class BlockHeader::_Internal {
 public:
  static const ::PROTOBUF_NAMESPACE_ID::Timestamp& timestamp(const BlockHeader* msg);
};

const ::PROTOBUF_NAMESPACE_ID::Timestamp&
BlockHeader::_Internal::timestamp(const BlockHeader* msg) {
  return *msg->timestamp_;
}
void BlockHeader::clear_timestamp() {
  if (GetArenaForAllocation() == nullptr && timestamp_ != nullptr) {
    delete timestamp_;
  }
  timestamp_ = nullptr;
}
BlockHeader::BlockHeader(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  parent_voter_ids_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:flow.entities.BlockHeader)
}
BlockHeader::BlockHeader(const BlockHeader& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      parent_voter_ids_(from.parent_voter_ids_) {
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
  payload_hash_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_payload_hash().empty()) {
    payload_hash_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_payload_hash(), 
      GetArenaForAllocation());
  }
  parent_voter_sig_data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_parent_voter_sig_data().empty()) {
    parent_voter_sig_data_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_parent_voter_sig_data(), 
      GetArenaForAllocation());
  }
  proposer_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_proposer_id().empty()) {
    proposer_id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_proposer_id(), 
      GetArenaForAllocation());
  }
  proposer_sig_data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_proposer_sig_data().empty()) {
    proposer_sig_data_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_proposer_sig_data(), 
      GetArenaForAllocation());
  }
  chain_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_chain_id().empty()) {
    chain_id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_chain_id(), 
      GetArenaForAllocation());
  }
  if (from._internal_has_timestamp()) {
    timestamp_ = new ::PROTOBUF_NAMESPACE_ID::Timestamp(*from.timestamp_);
  } else {
    timestamp_ = nullptr;
  }
  ::memcpy(&height_, &from.height_,
    static_cast<size_t>(reinterpret_cast<char*>(&view_) -
    reinterpret_cast<char*>(&height_)) + sizeof(view_));
  // @@protoc_insertion_point(copy_constructor:flow.entities.BlockHeader)
}

void BlockHeader::SharedCtor() {
id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
parent_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
payload_hash_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
parent_voter_sig_data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
proposer_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
proposer_sig_data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
chain_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&timestamp_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&view_) -
    reinterpret_cast<char*>(&timestamp_)) + sizeof(view_));
}

BlockHeader::~BlockHeader() {
  // @@protoc_insertion_point(destructor:flow.entities.BlockHeader)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void BlockHeader::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  parent_id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  payload_hash_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  parent_voter_sig_data_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  proposer_id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  proposer_sig_data_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  chain_id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete timestamp_;
}

void BlockHeader::ArenaDtor(void* object) {
  BlockHeader* _this = reinterpret_cast< BlockHeader* >(object);
  (void)_this;
}
void BlockHeader::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void BlockHeader::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void BlockHeader::Clear() {
// @@protoc_insertion_point(message_clear_start:flow.entities.BlockHeader)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  parent_voter_ids_.Clear();
  id_.ClearToEmpty();
  parent_id_.ClearToEmpty();
  payload_hash_.ClearToEmpty();
  parent_voter_sig_data_.ClearToEmpty();
  proposer_id_.ClearToEmpty();
  proposer_sig_data_.ClearToEmpty();
  chain_id_.ClearToEmpty();
  if (GetArenaForAllocation() == nullptr && timestamp_ != nullptr) {
    delete timestamp_;
  }
  timestamp_ = nullptr;
  ::memset(&height_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&view_) -
      reinterpret_cast<char*>(&height_)) + sizeof(view_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* BlockHeader::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
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
      // bytes payload_hash = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_payload_hash();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint64 view = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          view_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated bytes parent_voter_ids = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 58)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_parent_voter_ids();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<58>(ptr));
        } else
          goto handle_unusual;
        continue;
      // bytes parent_voter_sig_data = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 66)) {
          auto str = _internal_mutable_parent_voter_sig_data();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes proposer_id = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 74)) {
          auto str = _internal_mutable_proposer_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes proposer_sig_data = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 82)) {
          auto str = _internal_mutable_proposer_sig_data();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string chain_id = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 90)) {
          auto str = _internal_mutable_chain_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "flow.entities.BlockHeader.chain_id"));
          CHK_(ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* BlockHeader::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:flow.entities.BlockHeader)
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

  // bytes payload_hash = 5;
  if (!this->_internal_payload_hash().empty()) {
    target = stream->WriteBytesMaybeAliased(
        5, this->_internal_payload_hash(), target);
  }

  // uint64 view = 6;
  if (this->_internal_view() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(6, this->_internal_view(), target);
  }

  // repeated bytes parent_voter_ids = 7;
  for (int i = 0, n = this->_internal_parent_voter_ids_size(); i < n; i++) {
    const auto& s = this->_internal_parent_voter_ids(i);
    target = stream->WriteBytes(7, s, target);
  }

  // bytes parent_voter_sig_data = 8;
  if (!this->_internal_parent_voter_sig_data().empty()) {
    target = stream->WriteBytesMaybeAliased(
        8, this->_internal_parent_voter_sig_data(), target);
  }

  // bytes proposer_id = 9;
  if (!this->_internal_proposer_id().empty()) {
    target = stream->WriteBytesMaybeAliased(
        9, this->_internal_proposer_id(), target);
  }

  // bytes proposer_sig_data = 10;
  if (!this->_internal_proposer_sig_data().empty()) {
    target = stream->WriteBytesMaybeAliased(
        10, this->_internal_proposer_sig_data(), target);
  }

  // string chain_id = 11;
  if (!this->_internal_chain_id().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_chain_id().data(), static_cast<int>(this->_internal_chain_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "flow.entities.BlockHeader.chain_id");
    target = stream->WriteStringMaybeAliased(
        11, this->_internal_chain_id(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:flow.entities.BlockHeader)
  return target;
}

size_t BlockHeader::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:flow.entities.BlockHeader)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated bytes parent_voter_ids = 7;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(parent_voter_ids_.size());
  for (int i = 0, n = parent_voter_ids_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
      parent_voter_ids_.Get(i));
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

  // bytes payload_hash = 5;
  if (!this->_internal_payload_hash().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_payload_hash());
  }

  // bytes parent_voter_sig_data = 8;
  if (!this->_internal_parent_voter_sig_data().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_parent_voter_sig_data());
  }

  // bytes proposer_id = 9;
  if (!this->_internal_proposer_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_proposer_id());
  }

  // bytes proposer_sig_data = 10;
  if (!this->_internal_proposer_sig_data().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_proposer_sig_data());
  }

  // string chain_id = 11;
  if (!this->_internal_chain_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_chain_id());
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

  // uint64 view = 6;
  if (this->_internal_view() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64SizePlusOne(this->_internal_view());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData BlockHeader::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    BlockHeader::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*BlockHeader::GetClassData() const { return &_class_data_; }

void BlockHeader::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<BlockHeader *>(to)->MergeFrom(
      static_cast<const BlockHeader &>(from));
}


void BlockHeader::MergeFrom(const BlockHeader& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:flow.entities.BlockHeader)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  parent_voter_ids_.MergeFrom(from.parent_voter_ids_);
  if (!from._internal_id().empty()) {
    _internal_set_id(from._internal_id());
  }
  if (!from._internal_parent_id().empty()) {
    _internal_set_parent_id(from._internal_parent_id());
  }
  if (!from._internal_payload_hash().empty()) {
    _internal_set_payload_hash(from._internal_payload_hash());
  }
  if (!from._internal_parent_voter_sig_data().empty()) {
    _internal_set_parent_voter_sig_data(from._internal_parent_voter_sig_data());
  }
  if (!from._internal_proposer_id().empty()) {
    _internal_set_proposer_id(from._internal_proposer_id());
  }
  if (!from._internal_proposer_sig_data().empty()) {
    _internal_set_proposer_sig_data(from._internal_proposer_sig_data());
  }
  if (!from._internal_chain_id().empty()) {
    _internal_set_chain_id(from._internal_chain_id());
  }
  if (from._internal_has_timestamp()) {
    _internal_mutable_timestamp()->::PROTOBUF_NAMESPACE_ID::Timestamp::MergeFrom(from._internal_timestamp());
  }
  if (from._internal_height() != 0) {
    _internal_set_height(from._internal_height());
  }
  if (from._internal_view() != 0) {
    _internal_set_view(from._internal_view());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void BlockHeader::CopyFrom(const BlockHeader& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:flow.entities.BlockHeader)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BlockHeader::IsInitialized() const {
  return true;
}

void BlockHeader::InternalSwap(BlockHeader* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  parent_voter_ids_.InternalSwap(&other->parent_voter_ids_);
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
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &payload_hash_, lhs_arena,
      &other->payload_hash_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &parent_voter_sig_data_, lhs_arena,
      &other->parent_voter_sig_data_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &proposer_id_, lhs_arena,
      &other->proposer_id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &proposer_sig_data_, lhs_arena,
      &other->proposer_sig_data_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &chain_id_, lhs_arena,
      &other->chain_id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(BlockHeader, view_)
      + sizeof(BlockHeader::view_)
      - PROTOBUF_FIELD_OFFSET(BlockHeader, timestamp_)>(
          reinterpret_cast<char*>(&timestamp_),
          reinterpret_cast<char*>(&other->timestamp_));
}

::PROTOBUF_NAMESPACE_ID::Metadata BlockHeader::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_flow_2fentities_2fblock_5fheader_2eproto_getter, &descriptor_table_flow_2fentities_2fblock_5fheader_2eproto_once,
      file_level_metadata_flow_2fentities_2fblock_5fheader_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace entities
}  // namespace flow
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::flow::entities::BlockHeader* Arena::CreateMaybeMessage< ::flow::entities::BlockHeader >(Arena* arena) {
  return Arena::CreateMessageInternal< ::flow::entities::BlockHeader >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
