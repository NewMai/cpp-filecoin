/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CPP_FILECOIN_CORE_VM_RUNTIME_IMPL_RUNTIME_IMPL_HPP
#define CPP_FILECOIN_CORE_VM_RUNTIME_IMPL_RUNTIME_IMPL_HPP

#include "crypto/randomness/randomness_provider.hpp"
#include "vm/runtime/runtime.hpp"

namespace fc::vm::runtime {

  using crypto::randomness::ChainEpoch;
  using crypto::randomness::Randomness;
  using crypto::randomness::RandomnessProvider;
  using primitives::address::Address;

  class RuntimeImpl : public Runtime {
   public:
    RuntimeImpl(std::shared_ptr<RandomnessProvider> randomness_provider,
                ChainEpoch chain_epoch,
                Address immediate_caller);

    /** \copydoc Runtime::getCurrentEpoch() */
    ChainEpoch getCurrentEpoch() const override;

    /** \copydoc Runtime::getRandomness() */
    Randomness getRandomness(DomainSeparationTag tag,
                             ChainEpoch epoch) const override;

    /** \copydoc Runtime::getRandomness() */
    Randomness getRandomness(DomainSeparationTag tag,
                             ChainEpoch epoch,
                             Serialization seed) const override;

    /** \copydoc Runtime::getImmediateCaller() */
    Address getImmediateCaller() const override;

   private:
    std::shared_ptr<RandomnessProvider> randomness_provider_;
    ChainEpoch chain_epoch_;
    Address immediate_caller_;
  };

}  // namespace fc::vm::runtime

#endif  // CPP_FILECOIN_CORE_VM_RUNTIME_IMPL_RUNTIME_IMPL_HPP
