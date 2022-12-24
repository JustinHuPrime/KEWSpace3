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

#include <optional>

#include "glm/glm.hpp"
#include "model/damageable.h"
#include "model/movable.h"

namespace kewspace3::model {
class Ship : public Damageable, public Movable {
  /**
   * who owns this ship
   */
  uint8_t owner;

  /**
   * upgrade credits
   */
  uint32_t credits;

  /**
   * movement stats
   *
   * max acceleration, in m/s^2
   */
  static constexpr float ACCELERATION = 9.8;

  /**
   * starting stats: health and energy
   *
   * energy is twice the starting health
   */
  static constexpr float STARTING_HEALTH = 1e9;
  static constexpr float STARTING_ENERGY = STARTING_HEALTH / 2;
  /**
   * upgrade stats: health and energy
   *
   * increase health by 10%
   *
   * increase energy by 10%
   */
  static constexpr float UPGRADE_HEALTH = 0.1;
  static constexpr float UPGRADE_ENERGY = 0.1;

  /**
   * starting stats: laser
   *
   * require 25 seconds of full power to kill a ship (with no shields)
   *
   * only be able to fire for 5 seconds before running out
   */
  static constexpr float STARTING_LASER_POWER = STARTING_HEALTH / 25;
  static constexpr float STARTING_LASER_EFFICIENCY =
      (STARTING_LASER_POWER * 5) / STARTING_ENERGY;
  /**
   * upgrade stats: laser
   *
   * increase laser power by 10%
   *
   * increase laser efficiency by 10%
   */
  static constexpr float UPGRADE_LASER_POWER = 0.1;
  static constexpr float UPGRADE_LASER_EFFICIENCY = 0.1;

  /**
   * current stats: laser
   */
  float laserPower;
  float laserEfficiency;
  /**
   * Direction the laser is firing, as Euler angle from ship's forward, if any
   */
  std::optional<glm::vec3> laserTarget;

  /**
   * starting stats: cannon
   *
   * require 10 direct hits to kill a ship (with no shields)
   *
   * only be able to fire 50 shots before running out
   */
  static constexpr float STARTING_CANNON_DAMAGE = STARTING_HEALTH / 10;
  static constexpr float STARTING_CANNON_ENERGY = STARTING_ENERGY / 50;
  /**
   * upgrade stats: cannon
   *
   * increase cannon damage by 10%
   *
   * decrease cannon energy consumption by 10%
   */
  static constexpr float UPGRADE_CANNON_DAMAGE = 0.1;
  static constexpr float UPGRADE_CANNON_ENERGY = 0.1;

  /**
   * current stats: cannon
   */
  float cannonDamage;
  float cannonEnergy;

  /**
   * starting stats: missile
   *
   * require 2 direct hits to kill a ship (with no shields)
   *
   * magazine size of 4
   */
  static constexpr float STARTING_MISSILE_DAMAGE = STARTING_HEALTH / 2;
  static constexpr uint32_t STARTING_MISSILE_MAGAZINE_SIZE = 4;
  /**
   * upgrade stats: missile
   *
   * increase missile damage by 10%
   *
   * increase missile magazine size by 1
   */
  static constexpr float UPGRADE_MISSILE_DAMAGE = 0.1;
  static constexpr uint32_t UPGRADE_MISSILE_MAGAZINE_SIZE = 1;

  /**
   * current stats: missile
   */
  float missileDamage;
  uint32_t missileCount;
  uint32_t missileMagazineSize;
};
}  // namespace kewspace3::model
