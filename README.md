## Resource XML 
______
_aka the second lab for Cpp_


### Tasks:
* Realize `class ResourceXML`, that include following **methods**:
  * fabric method `create(xmlPath)` 
  * add the tag `add(nameTag or valueTag) -> iterator`
  * save xml file `save()`
  * find the tag `find(nameTag or valueTag) -> iterator` 
  * delete the tag `erase(); -> bool`
* Also class include following fields:
  * `file* xml` include object of `class ParserXML`, and following methods:
    * `add_tag()`
    * This field provide **Exception Guarantee**

* iterator may be type of `ResourceXML`