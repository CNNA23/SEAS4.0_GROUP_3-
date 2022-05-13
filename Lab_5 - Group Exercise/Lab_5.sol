//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.9.0;

contract BallastSystem
{
    function warning(uint waterLevelUS, uint waterLevelSensor) public view returns (string memory)
    {
        uint threshold = 450;
        if (waterLevelSensor > threshold || waterLevelUS > threshold)
        {
            return "Ballast tank full, please turn the pump off.";
        }
        else
        {
            return "Ballast tank not full, please do not turn the pump off.";
        }
    }
}
