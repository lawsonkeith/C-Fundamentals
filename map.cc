

// Example program
#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>
#include <map>

typedef uint16_t FrameID;
typedef uint16_t PacketID; 
typedef std::vector<uint8_t> PacketMem;
typedef std::map<PacketID,PacketMem> PacketMap;

int main()
{
	PacketID PackID;
	PacketMap packets;
	PacketMem pm = {6,7,8,9};

	// #### VECTOR CODE ########
	// assembly methods
	pm.insert(pm.begin(),77);	
	for (int i=1; i<=5; i++) pm.push_back(i);

	// iterator code
        for (PacketMem::const_iterator j = pm.begin(); j != pm.end(); ++j)
            std::cout << int(*j) << ' ';

	// longhand version
	std::cout << std::endl << (int)pm[0];
	std::cout << std::endl << (int)pm[1];
	std::cout << std::endl << (int)pm[2];
	std::cout << std::endl << (int)pm[3];
	std::cout << std::endl << (int)pm[4];
	std::cout << std::endl << (int)pm[5];
	std::cout << std::endl << (int)pm[6];
	std::cout << std::endl << (int)pm[7];
	std::cout << std::endl << (int)pm[8];
	std::cout << std::endl << (int)pm[9];
	std::cout << std::endl << (int)pm[110];

	// #### MAP / PAIR CODE ########
	// assembly
	packets.insert(packets.begin(), std::pair<PacketID,PacketMem> (3,{4,4,5,}));	
	packets.insert(packets.begin(), std::pair<PacketID,PacketMem> (5,{64,64,65,}));	
	std::cout << std::endl << "map size now " << packets.size() << std::endl;
        packets.insert(packets.begin(), std::pair<PacketID,PacketMem> (7,{94,84,95,}));
        std::cout << "map size now " << packets.size()  << std::endl;


	// iterator code
	// iterate over map
	for (PacketMap::const_iterator k = packets.begin(); k != packets.end(); ++k) {
		// which is a pair, print forst element
	    	std::cout << std::endl << int(k->first) << '-';
		// then iterate over 2nd
		for(PacketMem::const_iterator l = k->second.begin(); l != k->second.end(); ++l ) {
			std::cout << int(*l) << ",";
		}
	}
	std::cout << std::endl;

	// still what do you do!!!
	//
	std::pair<PacketMap::iterator,bool> rv;
	PacketMap::iterator m; 
      	rv = packets.insert(PacketMap::value_type(PackID,PacketMem()));

	//1st insertion ok	
	std::cout << std::endl << "test: " << rv.second  << std::endl;

	//uncomment to enable 2nd insert PackID = 99;
        rv = packets.insert(PacketMap::value_type(PackID,PacketMem()));
        //2nd fails
        std::cout << std::endl << "test: " << rv.second  << std::endl;

	//
//	PacketMap::iterator p=rv.first;
//	network::PacketHeader const *ph;
  //      p->second.resize(ph.packet_length);
//        memcpy(p->second.data(),ph.data(),ph.packet_length);    
}

