/*
MIT License

Copyright (c) 2024 Josh Schiavone

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

#include "fuckscript.hh"

namespace fuckscript {

  std::unordered_map<std::string, fsint_t> fscript_instr_map;

  template <typename Fsarg>
  inline void Handler<Fsarg>::fuckscript_increment(Environment& env, Fsarg execparam) {
    if (execparam) *env.fs_memory_pointer += 1; else return;
  }

  template <typename Fsarg>
  inline void Handler<Fsarg>::fuckscript_decrement(Environment& env, Fsarg execparam) {
    if (execparam) *env.fs_memory_pointer -= 1; else return;
  }

  template <typename Fsarg>
  inline void Handler<Fsarg>::fuckscript_shift_cell_frwd(Environment& env, Fsarg execparam) {
    if (execparam) {
      if (env.fs_memory_pointer != env.fscript_memory.end()--) {
        env.fs_memory_pointer++;
      }
    } else return;
  }

  template <typename Fsarg>
  inline void Handler<Fsarg>::fuckscript_shift_cell_bkwrd(Environment& env, Fsarg execparam) {
    if (execparam) {
      if (env.fs_memory_pointer != env.fscript_memory.begin()) {
        env.fs_memory_pointer--;
      }
    } else return;
  }

  template <typename Fsarg>
  inline void Handler<Fsarg>::fuckscript_show_stdout_buffer(Environment& env, Fsarg execparam) {
    if (execparam) {
      fs_word printablechar_ = *env.fs_memory_pointer;
      
      if (!isprint(printablechar_)) {
        std::cout << std::dec << static_cast<fsint_t> (printablechar_);
      } else {
        printablechar_ = char (*env.fs_memory_pointer);
        std::cout << printablechar_;
      }
      
    } else return;
  }


  template <typename Fsarg>
  inline void Handler<Fsarg>::fuckscript_read_stdin_buffer(Environment& env, Fsarg execparam) {
    if (execparam) {
      char fsinput;
      std::cin >> fsinput;  // Read the character
      if (isdigit(fsinput)) {
        (*env.fs_memory_pointer) = fsinput - '0';  // Convert from ASCII to integer
      }
    } else return;
  }


  template <typename Fsarg>
  inline void Handler<Fsarg>::fuckscript_push_instruction(Environment& env, fsint_t instr, Fsarg execparam) {
    if (execparam) env.fscript_instructions.push_back(instr); else return;
  }

  template <typename Fsarg>
  inline void Handler<Fsarg>::fuckscript_loop_parser(Environment& env, Fsarg execparm) {
    Parser parser;
    env.fscript_instruction_pointer++;
    loop_begin_ptr = env.fscript_instruction_pointer;
    while (*env.fs_memory_pointer) {
      env.fscript_instruction_pointer = loop_begin_ptr;
      while (*env.fscript_instruction_pointer != OPCODE_LOOP_END) {
        parser.interpret_fs_instructions(env, *env.fscript_instruction_pointer);
        env.fscript_instruction_pointer++;
      }
    }
  }

  template <typename Fsarg>
  inline void Handler<Fsarg>::fuckscript_reset_buffer(Environment& env, Fsarg execparam) {
    *env.fs_memory_pointer = FS_SUCCESS_CODE_STANDARD;
  }

  bool Parser::parse_fs_instructions(Environment& env, const char* sourcefilename) {
    sourcestream = std::ifstream(sourcefilename, std::ios::in);
    if (sourcestream.is_open()) {
      while (sourcestream >> instr_keyword) {
        if (bool kw_found = fscript_instr_map.find(instr_keyword) != fscript_instr_map.end()) {
          fuckscript_push_instruction(env, fscript_instr_map[instr_keyword], true);
        } else if (!kw_found) {
            std::cerr << "(error): invalid fuckscript instruction: "
              << instr_keyword;
            break;
        }
      }
    } else { throw exp::FSException("(error): .fks source cannot be located\n"); }
    return false;
  }

  void Parser::interpret_fs_instructions(Environment& env, fsint_t sourceinstr) {
    switch (sourceinstr) {
      case OPCODE_INCREMENT: fuckscript_increment(env, true); break;
      case OPCODE_DECREMENT: fuckscript_decrement(env, true); break;
      case OPCODE_MOVE_FRONT: fuckscript_shift_cell_frwd(env, true); break;
      case OPCODE_MOVE_BACK: fuckscript_shift_cell_bkwrd(env, true); break;
      case OPCODE_READ_STDIN_BUFFER: fuckscript_read_stdin_buffer(env, true); break;
      case OPCODE_SHOW_STDOUT_BUFFER: fuckscript_show_stdout_buffer(env, true); break;
      case OPCODE_LOOP_BEGIN: fuckscript_loop_parser(env, true); break;
      case OPCODE_RESET: fuckscript_reset_buffer(env, true); break;
    }
  }

  Environment::Environment() : fscript_memory(fuckscript::max_memory_size) {
    wipe_instruction_buffer(true);
    fs_memory_pointer = fscript_memory.begin();
  }

  void Environment::initialize() {
    fscript_instr_map[FS_INCREMENT_VALUE] = OPCODE_INCREMENT;
    fscript_instr_map[FS_DECREMENT_VALUE] = OPCODE_DECREMENT;
    fscript_instr_map[FS_CELL_SHIFT_BACK] = OPCODE_MOVE_BACK;
    fscript_instr_map[FS_CELL_SHIFT_FRONT] = OPCODE_MOVE_FRONT;
    fscript_instr_map[FS_READ_STDIN_BUFFER] = OPCODE_READ_STDIN_BUFFER;
    fscript_instr_map[FS_SHOW_STDOUT_BUFFER] = OPCODE_SHOW_STDOUT_BUFFER;
    fscript_instr_map[FS_LOOP_BEGIN] = OPCODE_LOOP_BEGIN;
    fscript_instr_map[FS_LOOP_END] = OPCODE_LOOP_END;
    fscript_instr_map[FS_RESET_BUFF] = OPCODE_RESET;
  }

  void Environment::wipe_instruction_buffer(bool execparam) {
    fscript_instructions.clear();
    fscript_instruction_pointer = fscript_instructions.begin();
  }

  bool Environment::check_fs_source_extension(std::string fsource) {
    if (fsource.substr(fsource.find_last_of(".") + 1) == "fks") {
      return true;
    } else { return false; }
  }

  bool fuckscript_main(const fs_word* fssource, bool fksmn) {
    std::unique_ptr<fuckscript::Environment> env = std::make_unique<fuckscript::Parser>();
    std::unique_ptr<fuckscript::Parser> parser = std::make_unique<fuckscript::Parser>();
    fsint_t loop_counter = 0;

    if (fksmn) { env->initialize(); } else return false;

    bool good_ext = env->check_fs_source_extension(fssource);
    if (fscript_should_succeed<bool> (good_ext, true)) {
      parser->parse_fs_instructions(*env, fssource);
      for (env->fscript_instruction_pointer = env->fscript_instructions.begin();
        env->fscript_instruction_pointer != env->fscript_instructions.end(); ++env->fscript_instruction_pointer) {
          if (*env->fscript_instruction_pointer == OPCODE_LOOP_BEGIN) {
            ++loop_counter;
          } else if (*env->fscript_instruction_pointer == OPCODE_LOOP_END) {
            --loop_counter;
          }
      }
      for (env->fscript_instruction_pointer = env->fscript_instructions.begin();
        env->fscript_instruction_pointer != env->fscript_instructions.end(); ++env->fscript_instruction_pointer) {
          parser->interpret_fs_instructions(*env, *env->fscript_instruction_pointer);
      }

      if (loop_counter != FS_SUCCESS_CODE_STANDARD) {
        std::cerr << "(error): 'WHATTHEFUCK' has no matching 'IAMFUCKED'";
      }
    } else {
        throw exp::FSException("(error): source file must contain a valid fuckscript extension\n");
    }

    return true;
  }

} // namespace: fuckscript
