// vim: set sts=8 ts=2 sw=2 tw=99 et:
//
// Copyright (C) 2013, David Anderson and AlliedModders LLC
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//  * Neither the name of AlliedModders LLC nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
#ifndef _include_amtl_platform_h_
#define _include_amtl_platform_h_

namespace ke {

#if defined(__EMSCRIPTEN__)
#    define KE_EMSCRIPTEN
#    define KE_POSIX
#elif defined(__NetBSD__)
#    define KE_NETBSD
#    define KE_BSD
#elif defined(__FreeBSD__)
#    define KE_FREEBSD
#    define KE_BSD
#elif defined(__OpenBSD__)
#    define KE_OPENBSD
#    define KE_BSD
#elif defined(__APPLE__)
#    define KE_MACOSX
#    define KE_MACH
#    define KE_BSD
#elif defined(__MACH__)
#    define KE_MACH
#    define KE_BSD
#elif defined(_WIN32)
#    define KE_WINDOWS
#elif defined(__linux__)
#    define KE_LINUX
#    define KE_POSIX
#elif defined(__sun__)
#    define KE_SOLARIS
#    define KE_POSIX
#endif

#if defined(KE_BSD)
#    define KE_POSIX
#endif

#if defined(__x86_64) || defined(__x86_64__) || defined(__amd64__) || defined(__amd64) || \
    (defined(_MSC_VER) && defined(_M_X64))
#    define KE_ARCH_X64
#elif defined(__i686) || defined(__i686__) || defined(__i386) || defined(__i386__) || \
    defined(i386) || (defined(_MSC_VER) && defined(_M_IX86))
#    define KE_ARCH_X86
#else
#    define KE_ARCH_UNKNOWN
#endif

// Create macros that exactly match the compiler - peeking past any tricks
// vendors play for interoperability.
#if defined(__clang__)
#    define KE_CXX_CLANG
#elif defined(__GNUC__)
#    define KE_CXX_GCC
#elif defined(_MSC_VER)
#    define KE_CXX_MSVC
#endif

#if defined(KE_CXX_CLANG) || defined(KE_CXX_GCC)
#    define KE_CXX_LIKE_GCC
#endif

} // namespace ke

#endif // _include_amtl_platform_h_
