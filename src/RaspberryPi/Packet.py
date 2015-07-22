class Packet:
	def __init__(self):
		self.data = {}

	#Associate a leg with angles to be moved in the next step
	def setLeg(self,id,leg):
		self.data.update({id : leg})

	#Get Leg id that will be moved
	def getLeg(self,id):
		return self.data[id]

	#Return the string to be sent to arduino
	def getPack(self):
		flg = list('00000000')
		for i in self.data.keys():
			flg[8-i] = '1'
		str = chr(222) + chr(230) + chr(222) + chr(int(''.join(flg),2))
		for leg in reversed(self.data.keys()):
			vec=self.data[leg].getAngles()
			for angle in vec:
				str = str + chr(angle)
		return str

#Class leg will be moved to the kinematics package
class Leg: 
	def __init__(self):
		self.data = []

	def setAngles(self,coxa,femur,tibia):
		self.data.extend([coxa,femur,tibia])

	def getAngles(self):
		return self.data