// SPDX-License-Identifier: MIT
pragma solidity >=0.5.0 <0.8.0;

contract Ballast_System {
    // Creating Variable Sensor Data //
    uint waterLevelUS;
    uint waterLevelSensor;

    // Creating Warning functions to check WaterLevel and making Alarms (Buzzers&LED) by received Sensor Values 
   
    function warning_US (uint waterLevelUS) public view returns (string memory)
    {
        uint threshold = 450;
        
        if (waterLevelUS > threshold)
        {
            return "Ballast tank is full! Buzzer & LED are on! Please turn the pump off.";
        }
        else
        {
            return "Ballast tank is not full! Buzzer & LED are off! Please do not turn the pump off.";
        }
    }

    function warning_WLS (uint waterLevelSensor) public view returns (string memory)
    {
        uint threshold = 450;
        if (waterLevelSensor > threshold)
        {
            return "Ballast tank is full! Buzzer & LED are on! Please turn the pump off.";
        }
        else
        {
            return "Ballast tank is not full! Buzzer & LED are off! Please do not turn the pump off.";
        }
    }

    // Creating Hash function to generate hash value for received Sensor Values

         function _sensor_US_Id(string memory _str)
    private view returns (uint)
    {
        uint rand_US=uint(keccak256(abi.encodePacked(_str)));
        return rand_US %waterLevelUS;
        
    } 

        function _sensor_WLS_Id(string memory _str)
    private view returns (uint)
    {
        uint rand_WLS=uint(keccak256(abi.encodePacked(_str)));
        return rand_WLS %waterLevelSensor;
    } 

    // To store the keys by mapping for sensors value

    mapping(address => uint) public sensors;  
}



