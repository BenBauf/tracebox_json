/**
 * Tracebox -- A middlebox detection tool
 *
 *  Copyright 2013-2015 by its authors. 
 *  Some rights reserved. See LICENSE, AUTHORS.
 */

#ifndef __PACKETMODIFICATION_H__
#define __PACKETMODIFICATION_H__

#include "crafter.h"

using namespace Crafter;

class Modification {
	/* Layer protocol where the modification occured. The protocol is as defined
	 * in Libcrafter.
	 */
	int layer_proto;

	/* Representation of the modification */
	std::string name;

	/* Offset compared to the start of the layer (in bits) */
	size_t offset;

	/* Length of the modification (in bits) */
	size_t len;

	/* Some private functions */
	std::string GetModifRepr() const;

protected:
	/* Field values helper */
	std::string field1_repr;
	std::string field2_repr;


public:
	Modification(int proto, std::string name, size_t offset, size_t len);
	Modification(int proto, FieldInfo *f1, FieldInfo *f2);
	Modification(Layer *l1, Layer *l2);

	int getOffset() const {
		return offset;
	}

	int GetOffsetBytes() const {
		return offset / 32;
	}

	size_t GetLength() const {
		return len;
	}

	std::string GetName() const {
		return name;
	}

	virtual ~Modification() {}

	virtual void Print(std::ostream& out = std::cout, bool verbose = false) const;
};

class Addition : public Modification {
public:
	Addition(Layer *l);

	virtual void Print(std::ostream& out, bool verbose = false) const;
};

class Deletion : public Modification {
public:
	Deletion(Layer *l);

	virtual void Print(std::ostream& out, bool verbose = false) const;
};

class PacketModifications : public std::vector<Modification *> {
	Packet *orig;
	Packet *modif;

public:
	PacketModifications(Packet *orig, Packet *modif) : orig(new Packet(*orig)), modif(modif) { }
	~PacketModifications();

	void Print(std::ostream& out = std::cout, bool verbose = false) const;
};

#endif
