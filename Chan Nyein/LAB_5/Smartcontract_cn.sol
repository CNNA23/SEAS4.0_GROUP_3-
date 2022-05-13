//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;

contract Factory {
    
    uint idDigits = 16;
    uint idModulus = idDigits ** 10;
    struct Product {
        string name; 
        uint id;
    }
    Product[] public products;
       
    /*function _createProduct(string memory _name, uint _id) private {
        products.push(Product(_name,_id));
    }*/

    function _generatedRandomId(string memory _str)
    private view returns (uint)
    {
        uint rand=uint(keccak256(abi.encodePacked(_str)));
        return rand %idModulus;
    }
    
    function createRandomProduct(string memory _name) public
    {
    uint randId = _generatedRandomId(_name);
    _createProduct(_name,randId);   
    }
    
       event NewProduct(uint ProductId, string name, uint id );
    function _createProduct(string memory _name, uint _id) 
   private {
     //uint ArrayProductid = products.push(Product(_name,_id))-1;
     //array.push(NewProduct(_ArrayProductid,_name)) ;
     products.push(Product(_name,_id));
     uint ProductId = (products.length- 1);
     emit NewProduct(ProductId,_name,_id);
   }
 
mapping(uint => address) public productToOwner;
mapping (address => uint) ownerProductCount;

  function _Ownership (uint _productId) public { 
        productToOwner[_productId] = msg.sender;
        ownerProductCount[msg.sender]++;
    }

function getProductsByOwner (address _owner) external view 
    returns(uint[] memory) {
     uint counter = 0;
     uint array = ownerProductCount[_owner];
     uint[] memory result = new uint[] (array);
     for (uint i = 0; i< products.length; i++) {
       if (productToOwner[i]== _owner){
         result[counter]= i;
         counter++;
       }
    }
     return result;
    }

    mapping (uint => uint) public age;
    modifier olderThan (uint _age, uint _userId)
    {
      require(age[_userId] >= _age );
      _;
    }

    function validationUsers( uint _userId) public view olderThan(18,_userId) {
    }

}


  


    







