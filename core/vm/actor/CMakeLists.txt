#
# Copyright Soramitsu Co., Ltd. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0
#

add_library(actor
    actor.cpp
    init_actor.cpp
    )
target_link_libraries(actor
    address
    cid
    hamt
    )
