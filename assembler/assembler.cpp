#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <bitset>
#include <cstdint>

// A function to convert register string (e.g., "r0") to its corresponding 3-bit binary representation
int registerToBits(const std::string& reg) {
    if (reg == "r0") return 0b000;
    if (reg == "r1") return 0b001;
    if (reg == "r2") return 0b010;
    if (reg == "r3") return 0b011;
    if (reg == "r4") return 0b100;
    if (reg == "r5") return 0b101;
    if (reg == "r6") return 0b110;
    if (reg == "r7") return 0b111;
    return -1; // Invalid register
}

// Function to assemble each instruction into a 16-bit machine code
uint16_t assembleInstruction(const std::string& operation, const std::string& rx, const std::string& ry) {
    // Instruction fields
    uint16_t instr = 0;

    // Set rx bits (15-13)
    instr |= (registerToBits(rx) << 13);

    // Set ry bits (12-10)
    instr |= (registerToBits(ry) << 10);

    // Set ALU operation bits (4-2)
    static std::unordered_map<std::string, int> aluOps = {
        {"add", 0b000}, {"sub", 0b001}, {"and", 0b010},
        {"or", 0b011}, {"xor", 0b100}, {"shl", 0b101},
        {"shr", 0b110}, {"cmp", 0b111}
    };

    if (aluOps.find(operation) != aluOps.end()) {
        instr |= (aluOps[operation] << 2);
    } else {
        std::cerr << "Unknown operation: " << operation << std::endl;
        return -1;
    }

    return instr;
}

std::string disasseble(uint16_t instr) {
    std::string operation;
    std::string rx;
    std::string ry;

    // Extract rx bits (15-13)
    int rxBits = (instr >> 13) & 0b111;
    switch (rxBits) {
        case 0b000: rx = "r0"; break;
        case 0b001: rx = "r1"; break;
        case 0b010: rx = "r2"; break;
        case 0b011: rx = "r3"; break;
        case 0b100: rx = "r4"; break;
        case 0b101: rx = "r5"; break;
        case 0b110: rx = "r6"; break;
        case 0b111: rx = "r7"; break;
    }

    // Extract ry bits (12-10)
    int ryBits = (instr >> 10) & 0b111;
    switch (ryBits) {
        case 0b000: ry = "r0"; break;
        case 0b001: ry = "r1"; break;
        case 0b010: ry = "r2"; break;
        case 0b011: ry = "r3"; break;
        case 0b100: ry = "r4"; break;
        case 0b101: ry = "r5"; break;
        case 0b110: ry = "r6"; break;
        case 0b111: ry = "r7"; break;
    }

    // Extract ALU operation bits (4-2)
    int aluOp = (instr >> 2) & 0b111;
    switch (aluOp) {
        case 0b000: operation = "add"; break;
        case 0b001: operation = "sub"; break;
        case 0b010: operation = "and"; break;
        case 0b011: operation = "or"; break;
        case 0b100: operation = "xor"; break;
        case 0b101: operation = "shl"; break;
        case 0b110: operation = "shr"; break;
        case 0b111: operation = "cmp"; break;
    }

    return operation + " " + rx + " " + ry;
}

// Function to read the assembly file and generate machine code
void assembleFile(const std::string& inputFile, const std::string& outputFile, std::string assemble) {
    std::ifstream input(inputFile);
    bool printOutput = outputFile.empty();
    std::ofstream output;
    if (!printOutput) {
        output.open(outputFile);
    }

    if (!input.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    std::string line;
    if(assemble == "true"){
        while (std::getline(input, line)) {
            uint16_t machineCode = 0;
        
            std::istringstream iss(line);
            std::string operation, rx, ry;
            iss >> operation >> rx >> ry;

            // Remove any commas or unnecessary characters from registers
            if (rx.back() == ',') rx.pop_back();

            // Assemble the instruction
            machineCode = assembleInstruction(operation, rx, ry);

            if(printOutput) {
            // Print the binary machine code to the console
            std::cout << std::bitset<16>(machineCode) << std::endl;
            } else {
                // Write the binary machine code to the output file
                output << std::bitset<16>(machineCode) << std::endl;
            }
        }
    } else {
        while (std::getline(input, line)) {
            u_int16_t value;
            try {
                value = static_cast<u_int16_t>(std::stoul(line));  // Use stoul for unsigned conversion
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid input: " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Value out of range: " << e.what() << std::endl;
            }
            std::string assembly = disasseble(value);
            
            if(printOutput) {
                // Print the binary machine code to the console
                std::cout << assembly << std::endl;
            } else {
                // Write the binary machine code to the output file
                output << assembly << std::endl;
            }
        }
    }

    input.close();
    output.close();
    if(printOutput){
        std::cout << "Assembling completed." << std::endl;
    } else {
        std::cout << "Assembling completed. Output written to " << outputFile << std::endl;
    }
}

int main(int argc, char* argv[]) {
    // Simple command-line interface (CLI)
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " -i <input file> -o <output file> -a (assemble)" << std::endl;
        return 1;
    }

    std::string inputFile, outputFile;
    std::string assemble = "not";

    // Parse command-line arguments
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-i" && i + 1 < argc) {
            inputFile = argv[++i];
        } else if (std::string(argv[i]) == "-o" && i + 1 < argc) {
            outputFile = argv[++i];
        } else if (std::string(argv[i]) == "-a") {
            assemble = "true";
        } else if (std::string(argv[i]) == "-d"){
            assemble = "false";
        }
    }

    assembleFile(inputFile, outputFile, assemble);    

    return 0;
}
