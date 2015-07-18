import Packet

joao = Packet.Packet()

pata1 = Packet.Leg()
pata2 = Packet.Leg()
pata3 = Packet.Leg()

pata1.setAngles(30,20,10)
pata2.setAngles(45,60,80)
pata3.setAngles(10,20,90)

joao.setLeg(1,pata1)
joao.setLeg(2,pata2)
joao.setLeg(5,pata3)

#Verify that the packet is well built
for character in joao.getPack():
  print character, character.encode('hex')