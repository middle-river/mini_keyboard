/* Copyright 2020 %YOUR_NAME%
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define Kxxx KC_NO
#define LAYOUT( \
  Kesc, Kf01, Kf02, Kf03, Kf04, Kf05, Kf06, Kf07, Kf08, Kf09, Kf10, Kf11, Kf12, Knum, Kpau, Kins, Kdel, \
  Khan, K__1, K__2, K__3, K__4, K__5, K__6, K__7, K__8, K__9, K__0, Kmin, Kcar, Kyen, Kbsp, \
  Ktab, K__q, K__w, K__e, K__r, K__t, K__y, K__u, K__i, K__o, K__p, Katm, Klsb, Kent, \
  Kcap, K__a, K__s, K__d, K__f, K__g, K__h, K__j, K__k, K__l, Ksem, Kcol, Krsb, \
  Klsh, K__z, K__x, K__c, K__v, K__b, K__n, K__m, Kcom, Kper, Ksla, Kbsl, Kupa, Krsh, \
  Klct, Kfnc, Kwin, Kalt, Kmuh, Kspc, Khen, Kkat, Kapp, Krct, Klta, Kdna, Krta \
) \
{ \
  { Kxxx, Kalt, Kxxx, Kxxx, Kmuh, K__q, K__e, K__t, K__y, K__8, K__i, Klsb, Ksem, Kbsl, Kupa }, \
  { Kxxx, Kxxx, Kwin, Kxxx, Ktab, K__2, K__4, K__r, K__k, K__u, K__0, Kyen, Katm, Kxxx, Krta }, \
  { Krct, Kxxx, Kxxx, Kxxx, Khan, Kf01, Kf03, Kf05, Kf07, Kf08, Kf10, Knum, Kf12, Kins, Kxxx }, \
  { Kxxx, Kxxx, Kxxx, Kxxx, K__a, Kspc, Kxxx, K__s, K__g, K__b, Kper, Krsb, Ksla, Khen, Kdna }, \
  { Kxxx, Kxxx, Kxxx, Kxxx, Kxxx, K__z, K__x, K__v, K__n, K__m, Kcom, Kent, Kapp, Kkat, Klta }, \
  { Kxxx, Kxxx, Kxxx, Krsh, Kesc, Kf02, Kf04, Kf06, K__6, Kf09, Kf11, Kpau, Kbsp, Kdel, Kxxx }, \
  { Kxxx, Kxxx, Kxxx, Klsh, Kcap, K__1, K__3, K__5, K__7, K__o, K__9, Kcar, K__p, Kxxx, Kxxx }, \
  { Klct, Kxxx, Kxxx, Kxxx, Kfnc, K__w, K__d, K__c, K__h, K__j, K__f, Kcol, Kmin, K__l, Kxxx } \
}
