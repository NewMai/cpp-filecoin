/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "storage/ipfs/impl/blockservice_impl.hpp"

using fc::storage::ipfs::Block;

namespace fc::storage::ipfs {
  outcome::result<void> BlockServiceImpl::addBlock(
      const Block &block) {
    return local_storage_.set(block.getCID(), block.getContent());
  }

  outcome::result<bool> BlockServiceImpl::has(const CID &cid) const {
    return local_storage_.contains(cid);
  }

  outcome::result<Block::Content> BlockServiceImpl::getBlockContent(const CID &cid) const {
    outcome::result<Block::Content> data = local_storage_.get(cid);
    return data ? data : BlockServiceError::NOT_FOUND;
  }

  outcome::result<void> BlockServiceImpl::removeBlock(const CID &cid) {
    if (local_storage_.remove(cid).has_error()) {
      return BlockServiceError::NOT_FOUND;
    }
    return outcome::success();
  }
}  // namespace fc::storage::ipfs

OUTCOME_CPP_DEFINE_CATEGORY(fc::storage::ipfs, BlockServiceError, e) {
  using fc::storage::ipfs::BlockServiceError;
  switch (e) {
    case BlockServiceError::NOT_FOUND:
      return "BlockServiceError: block not found";
    default:
      return "BlockServiceError: unknown error";
  }
}
