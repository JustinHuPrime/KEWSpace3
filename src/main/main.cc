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

#include <iostream>

using namespace std;

namespace {
void showUsage() {
  cerr << "Usage:" << endl;
  cerr << "  kewspace3 host <password>" << endl;
  cerr << "  kewspace3 join <hostname> <password>" << endl;
}
}  // namespace

/**
 * Runs KEWSpace 3.
 * Command lines accepted:
 *  - kewspace3 host new <filename> <password>
 *  - kewspace3 host saved <filename> <password>
 *  - kewspace3 join <hostname> <password>
 */
int main(int argc, char *argv[]) {
  switch (argc) {
    case 3: {
      if (argv[1] != "join"s) {
        showUsage();
        return 1;
      }

      cout << "Joining game..." << endl;
    }
    case 4: {
      if (argv[1] != "host"s) {
        showUsage();
        return 1;
      }

      if (argv[2] == "new"s) {
        cout << "Hosting new game..." << endl;
      } else if (argv[2] == "saved"s) {
        cout << "Hosting saved game..." << endl;
      } else {
        showUsage();
        return 1;
      }
    }
    default: {
      showUsage();
      return 1;
    }
  }
}
