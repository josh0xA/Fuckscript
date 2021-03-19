/*
MIT License

Copyright (c) 2021 Josh Schiavone

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <deque>
#include <algorithm>
#include <map>
#include <memory>

#include <ctype.h>
#include <stdio.h>

#define FS_SUCCESS_CODE_STANDARD 0
#define FS_ERROR_CODE_STANDARD -1

#define FS_SET_VALUE(s_value, k_value) ((s_value) = (k_value))
#define FS_FLUSH(ENDSTREAM) (std::cout << ENDSTREAM)

/*
 *Fuckscript instructions
 *as predefs
*/
#define FS_INCREMENT_VALUE "fuckplus"
#define FS_DECREMENT_VALUE "fucksub"
#define FS_CELL_SHIFT_BACK "fuckshiftback"
#define FS_CELL_SHIFT_FRONT "fuckshiftfront"
#define FS_READ_STDIN_BUFFER "fuckin"
#define FS_SHOW_STDOUT_BUFFER "fuckout"
#define FS_LOOP_BEGIN "fuckbegin"
#define FS_LOOP_END "fuckend"
#define FS_RESET_BUFF "fuckset"
/*
 * Fuckscript instructions as
 * opcode
*/
#define OPCODE_MOVE_FRONT 1
#define OPCODE_MOVE_BACK 2
#define OPCODE_INCREMENT 3
#define OPCODE_DECREMENT 4
#define OPCODE_READ_STDIN_BUFFER 5
#define OPCODE_SHOW_STDOUT_BUFFER 6
#define OPCODE_LOOP_BEGIN 7
#define OPCODE_LOOP_END 8
#define OPCODE_RESET 9

typedef char fs_word;
typedef uint32_t fs32;
typedef int fsint_t;


namespace fuckscript {
  constexpr fs_word nullchar = '\0';
  const fsint_t max_memory_size = 30000; // tape

  template <typename FType>
  FType fscript_should_succeed(FType successor, FType successor_value) {
    return (std::move(successor) == successor_value);
  }

  class Environment {
  public:
    std::deque<fsint_t> fscript_instructions, fscript_memory;
    std::deque<fsint_t>::iterator fscript_instruction_pointer, fs_memory_pointer;
    explicit Environment();

    void initialize();
    void wipe_instruction_buffer(bool execparam);
    bool check_fs_source_extension(std::string fsource);
  };

  template <typename Fsarg>
  class Handler : public Environment {
  public:
    inline void fuckscript_increment(Environment& env, Fsarg execparam);
    inline void fuckscript_decrement(Environment& env, Fsarg execparam);
    inline void fuckscript_shift_cell_frwd(Environment& env, Fsarg execparam);
    inline void fuckscript_shift_cell_bkwrd(Environment& env, Fsarg execparam);
    inline void fuckscript_read_stdin_buffer(Environment& env, Fsarg execparam);
    inline void fuckscript_show_stdout_buffer(Environment& env, Fsarg execparam);
    inline void fuckscript_reset_buffer(Environment& env, Fsarg execparam);
    inline void fuckscript_loop_parser(Environment& env, Fsarg execparam);
    inline void fuckscript_push_instruction(Environment& env, fsint_t instr, Fsarg execparam);
  private:
    //fs_word printablechar_;
    std::deque<fsint_t>::iterator loop_begin_ptr;
  };

  class Parser : public Handler<bool> {
  public:
    bool parse_fs_instructions(Environment& env, const char* sourcefilename);
    void interpret_fs_instructions(Environment& env, fsint_t sourceinstr);
  private:
    std::ifstream sourcestream;
    std::string instr_keyword;
  };

  namespace exp {
    #include <exception>
    class FSException : public std::exception {
    public:
      FSException(const char* const message): errmessage_ {message} {};

      const char* what() const noexcept { return errmessage_; }
    private:
      const char* errmessage_;
    };
  }

  bool fuckscript_main(const fs_word*, bool fksmn);
}
