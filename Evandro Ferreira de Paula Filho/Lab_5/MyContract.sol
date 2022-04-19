//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.9.0;

contract Factory
{
    uint idDigits = 16;
    uint idModulus = 10^idDigits;
    struct Product
    {
        uint id;
        string name;
    }
    Product[] public products;

    event NewProduct(uint ArrayProductId, string name, uint id);

    function _createProducts(string memory _name, uint _id) private returns (Product[] memory) 
    {
        uint productId = products.push(Product(_id,_name))[-1]; 
        emit NewProduct(productId, _name, _id);
        return products;
    }

    function _generateRandonId(string memory _name) private 
    {
        uint rand = keccak256(abi.encodePacked(_name));
        return rand % idModulus;        
    }

    function createRandomProduct(string memory _name) public
    {
       uint randId =  _generateRandonId(_name);
       _createProducts(_name, randId);
    }

    mapping (uint => address) public productToOwner;
    mapping (address => uint) ownerProductCount;

    function Ownership(uint productId) public
    {
        productToOwner[productId] = msg.sender;
        ownerProductCount[msg.sender] = ownerProductCount[msg.sender]++;
    }
    function getProductsByOwner(address named_owner) external view
    {
        uint counter = 0;
        uint result;
        for(uint i=0; i < ownerProductCount[named_owner]; i++)
        {
            if (productToOwner[i] == named_owner)
            {
                result[counter] = i;
                counter++;
            }
        }
        return result;
    }
    mapping (uint => uint) public age;
    
    modifier olderThan(uint _age, uint _userId)
    {
        require(age[_userId] >= _age);
        _;
    }

    function validationUsers(uint _userId) public view olderThan (18, _userId)
    {

    }


}

