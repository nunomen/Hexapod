class Packet:
	def __init__(self):
		self.data = {}

	def setLeg(self,id,leg):
		self.data.update({id : leg})

	def getLeg(self,id):
		return self.data[id]

	def getPack(self):
		str = ""
		for x in range(1,6):
			str = str + ""
		return str

class Leg:
	def __init__(self):
		self.data = []

	def setAngles(self,coxa,femur,tibia):
		self.data.extend([coxa,femur,tibia])

	def getAngles(self):
		return self.data