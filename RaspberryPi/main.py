import Packet,serial, codecs

joao = Packet.Packet()

pata1 = Packet.Leg()
pata2 = Packet.Leg()
pata3 = Packet.Leg()
pata4 = Packet.Leg()
pata5 = Packet.Leg()

pata1.set_angles(30,20,20)
pata2.set_angles(45,60,80)
pata3.set_angles(30,43,31)
pata4.set_angles(19,41,42)
pata5.set_angles(32,20,90)

joao.set_leg(1,pata1)
joao.set_leg(2,pata2)
joao.set_leg(3,pata3)
joao.set_leg(4,pata4)
joao.set_leg(5,pata5)

# Verify that the packet is well built
for character in joao.get_pack():
    print(character, codecs.encode(int(character), 'hex'))

#ser = serial.Serial('/dev/ttyACM0', 9600)

#for x in joao.get_pack():
    #ser.write(x)