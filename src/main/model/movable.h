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

#include <glm/glm.hpp>

namespace kewspace3::model {
class Movable {
  /**
   * Position, velocity, acceleration, in m, m/s, m/s^2
   *
   * Position and velocity are in world coordinates, acceleration is in
   * ship coordinates
   */
  glm::vec3 position;
  glm::vec3 velocity;
  glm::vec3 acceleration;

  /**
   * Attitude, angular velocity, angular acceleration, in rad, rad/s, rad/s^2
   *
   * As Euler angles to convert from world to ship frame
   */
  glm::vec3 attitude;
  glm::vec3 angularVelocity;
  glm::vec3 angularAcceleration;
};
}  // namespace kewspace3::model
