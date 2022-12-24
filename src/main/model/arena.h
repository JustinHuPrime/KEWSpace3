// Copyright 2022 Justin Hu
//
// This file is part of KEWSpace 3.
//
// KEWSpace 3 is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// KEWSpace 3 is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License
// for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with KEWSpace 3. If not, see <https://www.gnu.org/licenses/>.
//
// SPDX-License-Identifier: AGPL-3.0-or-later

#include <vector>

#include "model/missile.h"
#include "model/shell.h"
#include "model/ship.h"

namespace kewspace3::model {
class Arena {
  std::vector<Ship> ships;
  std::vector<Shell> shells;
  std::vector<Missile> missiles;

  /**
   * arena dimensions, m
   *
   * within the INNER_RADIUS, nothing happens
   * between the INNER_RADIUS and the OUTER_RADIUS, ships start accelerating
   * towards the center of the arena; at the OUTER_RADIUS, acceleration is twice
   * ship acceleration
   */
  static constexpr float INNER_RADIUS = 1e4;
  static constexpr float OUTER_RADIUS = 3e4;
};
}  // namespace kewspace3::model
