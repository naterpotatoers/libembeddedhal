// The MIT License (MIT)
//
// Copyright (c) 2018 Mateusz Pusz
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

// IWYU pragma: begin_exports
#include <units/isq/dimensions/momentum.h>
#include <units/quantity.h>
#include <units/symbol_text.h>
// IWYU pragma: end_exports

#include <units/isq/si/mass.h>
#include <units/isq/si/speed.h>
#include <units/unit.h>

namespace units::isq::si {

struct kilogram_metre_per_second : unit<kilogram_metre_per_second> {};
struct dim_momentum : isq::dim_momentum<dim_momentum, kilogram_metre_per_second, dim_mass, dim_speed> {};

template<UnitOf<dim_momentum> U, Representation Rep = double>
using momentum = quantity<dim_momentum, U, Rep>;

#ifndef UNITS_NO_LITERALS

inline namespace literals {

// kg*m/s
constexpr auto operator"" _q_kg_m_per_s(unsigned long long l)
{
  gsl_ExpectsAudit(std::in_range<std::int64_t>(l));
  return momentum<kilogram_metre_per_second, std::int64_t>(static_cast<std::int64_t>(l));
}
constexpr auto operator"" _q_kg_m_per_s(long double l) { return momentum<kilogram_metre_per_second, long double>(l); }

}  // namespace literals

#endif  // UNITS_NO_LITERALS

}  // namespace units::isq::si

#ifndef UNITS_NO_ALIASES

namespace units::aliases::isq::si::inline momentum {

template<Representation Rep = double>
using kg_m_per_s = units::isq::si::momentum<units::isq::si::kilogram_metre_per_second, Rep>;

}  // namespace units::aliases::isq::si::inline momentum

#endif  // UNITS_NO_ALIASES
