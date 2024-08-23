#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
int main(void){
  std::cout << "Choco4 Assembler\nBy Best_Archer\nVersion 1.0.1 \"Sorcerer\"\n-------------------------\nEnter the input assembly file path.\n";
  std::string current_line = "\0";
  std::getline(std::cin, current_line);
  std::ifstream ifile(current_line);
  std::cout << "Now, enter the output file path.\n";
  std::getline(std::cin, current_line);
  std::ofstream ofile(current_line);
  std::vector<std::string> tokens;
  while(std::getline(ifile, current_line)){
    std::istringstream iss(current_line);
    std::string field= "\0";
    bool running = true;
    while(std::getline(iss, field, ' ') && running == true){
      if(field[0] == '/' == field[1]) running = false;
      else tokens.push_back(field);
    }
  }
  ifile.close();
  uint8_t byte = 0, bytes = 1;
  for(unsigned i = 0; i < tokens.size(); ++i){
    if(bytes != 1) bytes = 1;
    if(tokens[i] == "STL") byte = 0b00000000;
    else if(tokens[i] == "NOP") byte = 0b00000001;
    else if(tokens[i] == "RET") byte = 0b00000010;
    else if(tokens[i] == "LDP"){
      byte = 0b00000011;
      bytes = 2;
    }
    else if(tokens[i] == "INC"){
      byte = 0b00000100;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'INC [num]' <- [num] > 3, [num] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
    }
    else if(tokens[i] == "DEC"){
      byte = 0b00001000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'DEC [num]' <- [num] > 3, [num] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
    }
    else if(tokens[i] == "LSH"){
      byte = 0b00001100;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'LSH [num]' <- [num] > 3, [num] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
      bytes = 2;
    }
    else if(tokens[i] == "RSH"){
      byte = 0b00010000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'RSH [num]' <- [num] > 3, [num] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
      bytes = 2;
    }
    else if(tokens[i] == "LIM"){
      byte = 0b00010100;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'LIM [num]' <- [num] > 3, [num] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
      bytes = 2;
    }
    else if(tokens[i] == "MST"){
      byte = 0b00011000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'MST [num]' <- [num] > 3, [num] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
      bytes = 2;
    }
    else if(tokens[i] == "MLD"){
      byte = 0b00011100;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'MLD [num]' <- [num] > 3, [num] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
      bytes = 2;
    }
    else if(tokens[i] == "DST"){
      byte = 0b00100000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'DST [num]' <- [num] > 3, [num] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
      bytes = 2;
    }
    else if(tokens[i] == "DLD"){
      byte = 0b00100100;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'DLD [num]' <- [num] > 3, [num] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
      bytes = 2;
    }
    else if(tokens[i] == "PUSH"){
      byte = 0b00101000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'PUSH [num]' <- [num] > 3, [num] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
    }
    else if(tokens[i] == "POP"){
      byte = 0b00101100;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'POP [num]' <- [num] > 3, [num] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
    }
    else if(tokens[i] == "ADD"){
      byte = 0b00110000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b1100;
        std::cout << "WARNING: 'ADD [num1] [num2]' <- [num1] > 3, [num1] ROUNDED DOWN TO 3.\n";
      }
      else byte += ((uint8_t) std::stoul(tokens[i]) * 4);
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'ADD [num1] [num2]' <- [num2] > 3, [num2] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
    }
    else if(tokens[i] == "SUB"){
      byte = 0b01000000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b1100;
        std::cout << "WARNING: 'SUB [num1] [num2]' <- [num1] > 3, [num1] ROUNDED DOWN TO 3.\n";
      }
      else byte += ((uint8_t) std::stoul(tokens[i]) * 4);
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'SUB [num1] [num2]' <- [num2] > 3, [num2] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
    }
    else if(tokens[i] == "AND"){
      byte = 0b01010000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b1100;
        std::cout << "WARNING: 'AND [num1] [num2]' <- [num1] > 3, [num1] ROUNDED DOWN TO 3.\n";
      }
      else byte += ((uint8_t) std::stoul(tokens[i]) * 4);
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'AND [num1] [num2]' <- [num2] > 3, [num2] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
    }
    else if(tokens[i] == "OR"){
      byte = 0b01100000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b1100;
        std::cout << "WARNING: 'OR [num1] [num2]' <- [num1] > 3, [num1] ROUNDED DOWN TO 3.\n";
      }
      else byte += ((uint8_t) std::stoul(tokens[i]) * 4);
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'OR [num1] [num2]' <- [num2] > 3, [num2] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
    }
    else if(tokens[i] == "XOR"){
      byte = 0b01110000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b1100;
        std::cout << "WARNING: 'XOR [num1] [num2]' <- [num1] > 3, [num1] ROUNDED DOWN TO 3.\n";
      }
      else byte += ((uint8_t) std::stoul(tokens[i]) * 4);
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'XOR [num1] [num2]' <- [num2] > 3, [num2] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
    }
    else if(tokens[i] == "CMP"){
      byte = 0b10000000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b1100;
        std::cout << "WARNING: 'CMP [num1] [num2]' <- [num1] > 3, [num1] ROUNDED DOWN TO 3.\n";
      }
      else byte += ((uint8_t) std::stoul(tokens[i]) * 4);
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'CMP [num1] [num2]' <- [num2] > 3, [num2] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
    }
    else if(tokens[i] == "TEST"){
      byte = 0b10010000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b1100;
        std::cout << "WARNING: 'TEST [num1] [num2]' <- [num1] > 3, [num1] ROUNDED DOWN TO 3.\n";
      }
      else byte += ((uint8_t) std::stoul(tokens[i]) * 4);
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'TEST [num1] [num2]' <- [num2] > 3, [num2] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
    }
    else if(tokens[i] == "MOV"){
      byte = 0b10100000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b1100;
        std::cout << "WARNING: 'MOV [num1] [num2]' <- [num1] > 3, [num1] ROUNDED DOWN TO 3.\n";
      }
      else byte += ((uint8_t) std::stoul(tokens[i]) * 4);
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'MOV [num1] [num2]' <- [num2] > 3, [num2] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
    }
    else if(tokens[i] == "PST"){
      byte = 0b10110000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b1100;
        std::cout << "WARNING: 'PST [num1] [num2]' <- [num1] > 3, [num1] ROUNDED DOWN TO 3.\n";
      }
      else byte += ((uint8_t) std::stoul(tokens[i]) * 4);
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'PST [num1] [num2]' <- [num2] > 3, [num2] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
    }
    else if(tokens[i] == "PLD"){
      byte = 0b11000000;
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b1100;
        std::cout << "WARNING: 'PLD [num1] [num2]' <- [num1] > 3, [num1] ROUNDED DOWN TO 3.\n";
      }
      else byte += ((uint8_t) std::stoul(tokens[i]) * 4);
      if(std::stoul(tokens[++i]) > 3){
        byte += 0b11;
        std::cout << "WARNING: 'PLD [num1] [num2]' <- [num2] > 3, [num2] ROUNDED DOWN TO 3.\n";
      }
      else byte += (uint8_t) std::stoul(tokens[i]);
    }
    else if(tokens[i] == "JMP"){
      byte = 0b11010000;
      if(((std::stoul(tokens[i + 1]) & 0x0f00) >> 8) > 0b1111){
        byte += 0b1111;
        std::cout << "WARNING: 'JMP [addr top nibble]' <- [addr top nibble] > 15, [addr top nibble] ROUNDED DOWN TO 15.\n";
      }
      else byte += (uint8_t) ((std::stoul(tokens[i + 1]) & 0x0f00) >> 8);
      bytes = 2;
    }
    else if(tokens[i] == "CALL"){
      byte = 0b11100000;
      if(((std::stoul(tokens[i + 1]) & 0x0f00) >> 8) > 0b1111){
        byte += 0b1111;
        std::cout << "WARNING: 'CALL [addr top nibble]' <- [addr top nibble] > 15, [addr top nibble] ROUNDED DOWN TO 15.\n";
      }
      else byte += (uint8_t) ((std::stoul(tokens[i + 1]) & 0x0f00) >> 8);
      bytes = 2;
    }
    else if(tokens[i] == "PRD"){
      byte = 0b11110000;
      if(std::stoul(tokens[++i]) > 1){
        byte += 0b1000;
        std::cout << "WARNING: 'PRD [num1] [num2] [num3] [num4]' <- [num1] > 1, [num1] ROUNDED DOWN TO 1.\n";
      }
      else byte += ((uint8_t) std::stoul(tokens[i]) << 3);
      if(std::stoul(tokens[++i]) > 1){
        byte += 0b100;
        std::cout << "WARNING: 'PRD [num1] [num2] [num3] [num4]' <- [num2] > 1, [num2] ROUNDED DOWN TO 1.\n";
      }
      else byte += (uint8_t) (std::stoul(tokens[i]) << 2);
      if(std::stoul(tokens[++i]) > 1){
        byte += 0b10;
        std::cout << "WARNING: 'PRD [num1] [num2] [num3] [num4]' <- [num3] > 1, [num3] ROUNDED DOWN TO 1.\n";
      }
      else byte += (uint8_t) (std::stoul(tokens[i]) << 1);
      if(std::stoul(tokens[++i]) > 1){
        byte += 0b1;
        std::cout << "WARNING: 'PRD [num1] [num2] [num3] [num4]' <- [num4] > 1, [num4] ROUNDED DOWN TO 1.\n";
      }
      else byte += (uint8_t) (std::stoul(tokens[i]) << 2);
    }
    ofile << byte;
    if(bytes > 1){
      for(uint8_t i = 0; i < bytes; ++i){
        byte = 0xff & (uint8_t) std::stoul(tokens[++i]);
        ofile << byte;
      }
    }
  }
  ofile.close();
  std::cout << "Press enter to close.\n";
  std::cin.ignore();
  return 0;
}
