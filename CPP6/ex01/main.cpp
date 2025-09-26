#include "Serializer.hpp"

void testBasicSerialization() {
    std::cout << "=== BASIC SERIALIZATION TEST ===" << std::endl;
    
    Data* original = new Data();
    original->value = 42;
    original->name = "Example";

    std::cout << "Original Data address: " << original << std::endl;
    std::cout << "Original Data value: " << original->value << std::endl;
    std::cout << "Original Data name: " << original->name << std::endl;

    uintptr_t serialized = Serializer::serialize(original);
    std::cout << "Serialized Data (uintptr_t): " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data address: " << deserialized << std::endl;
    std::cout << "Deserialized Data value: " << deserialized->value << std::endl;
    std::cout << "Deserialized Data name: " << deserialized->name << std::endl;

    if (original == deserialized) {
        std::cout << "Success! Serialization/Deserialization worked correctly!" << std::endl;
        std::cout << "Original and deserialized pointers are identical." << std::endl;
    } else {
        std::cout << "Error! Pointers don't match!" << std::endl;
    }

    delete original;
}

void testInvalidDeserialization() {
    std::cout << "\n=== INVALID DESERIALIZATION TESTS ===" << std::endl;
    
    std::cout << "\n--- Test 1: Random invalid values ---" << std::endl;
    uintptr_t invalidValues[] = {123, 456, 999, 0xDEADBEEF, 0x12345678};
    
    for (int i = 0; i < 5; i++) {
        std::cout << "Attempting to deserialize invalid value: " << invalidValues[i] << std::endl;
        
        Data* dangerous = Serializer::deserialize(invalidValues[i]);
        std::cout << "Deserialized pointer: " << dangerous << std::endl;
        
        std::cout << "WARNING: This pointer is likely invalid and dangerous to use!" << std::endl;
        std::cout << "Accessing this memory could cause segmentation fault!" << std::endl;
    }
    
    std::cout << "\n--- Test 2: Use after delete (dangerous!) ---" << std::endl;
    Data* temp = new Data();
    temp->value = 100;
    temp->name = "Temporary";
    
    uintptr_t serializedTemp = Serializer::serialize(temp);
    std::cout << "Original address: " << temp << std::endl;
    std::cout << "Serialized value: " << serializedTemp << std::endl;
    
    delete temp;
    std::cout << "Object deleted!" << std::endl;
    
    Data* deletedPtr = Serializer::deserialize(serializedTemp);
    std::cout << "Deserialized address: " << deletedPtr << std::endl;
    std::cout << "WARNING: This points to deleted memory!" << std::endl;
    std::cout << "Accessing this memory is undefined behavior!" << std::endl;
    
}

void testNullPointer() {
    std::cout << "\n=== NULL POINTER TEST ===" << std::endl;
    
    Data* nullPtr = NULL;
    uintptr_t serialized = Serializer::serialize(nullPtr);
    Data* deserialized = Serializer::deserialize(serialized);
    
    std::cout << "Null pointer serialized: " << serialized << std::endl;
    std::cout << "Null pointer deserialized: " << deserialized << std::endl;
    
    if (nullPtr == deserialized && serialized == 0) {
        std::cout << "Null pointer test PASSED!" << std::endl;
        std::cout << "Note: NULL serializes to 0, which is safe to deserialize back to NULL" << std::endl;
    } else {
        std::cout << "Null pointer test FAILED!" << std::endl;
    }
}

int main() 
{
    std::cout << "========================================" << std::endl;
    std::cout << "    SERIALIZER COMPREHENSIVE TESTS" << std::endl;
    std::cout << "========================================" << std::endl;
    
    testBasicSerialization();
    testNullPointer();
    testInvalidDeserialization();
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "           ALL TESTS COMPLETED" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}