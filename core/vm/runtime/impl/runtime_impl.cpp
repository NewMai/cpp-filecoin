/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "vm/runtime/impl/runtime_impl.hpp"

using fc::crypto::randomness::ChainEpoch;
using fc::crypto::randomness::Randomness;
using fc::crypto::randomness::Serialization;
using fc::primitives::address::Address;
using fc::vm::runtime::RuntimeImpl;

RuntimeImpl::RuntimeImpl(
    std::shared_ptr<RandomnessProvider> randomness_provider,
    ChainEpoch chain_epoch,
    Address immediate_caller)
    : randomness_provider_{std::move(randomness_provider)},
      chain_epoch_{chain_epoch},
      immediate_caller_{std::move(immediate_caller)} {}

ChainEpoch RuntimeImpl::getCurrentEpoch() const {
  return chain_epoch_;
}

Randomness RuntimeImpl::getRandomness(DomainSeparationTag tag,
                                      ChainEpoch epoch) const {
  return randomness_provider_->deriveRandomness(tag, Serialization{}, epoch);
}

Randomness RuntimeImpl::getRandomness(DomainSeparationTag tag,
                                      ChainEpoch epoch,
                                      Serialization seed) const {
  return randomness_provider_->deriveRandomness(tag, seed, epoch);
}

Address RuntimeImpl::getImmediateCaller() const {
  return immediate_caller_;
}
