/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef FILECOIN_STORAGE_IPFS_BLOCKSERVICE_IMPL_HPP
#define FILECOIN_STORAGE_IPFS_BLOCKSERVICE_IMPL_HPP

#include "storage/ipfs/blockservice.hpp"

namespace fc::storage::ipfs {
  class BlockServiceImpl : public BlockService {
   public:
    /**
     * @brief Construct block service
     * @todo Add exchange for remote storage
     * @param data_store
     */
    explicit BlockServiceImpl(IpfsDatastore &data_store)
        : local_storage_{data_store} {}

    outcome::result<void> addBlock(const Block &block) override;

    outcome::result<bool> has(const CID &cid) const override;

    outcome::result<Block::Content> getBlockContent(
        const CID &cid) const override;

    outcome::result<void> removeBlock(const CID &cid) override;

   private:
    IpfsDatastore &local_storage_; /**< Local data storage */
  };
}  // namespace fc::storage::ipfs

#endif
