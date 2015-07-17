class Packet:
	def __init__(self):
		self.data = 1

	def setLeg(self,id,coxa,femur,tibia):
		self.data = id
		return self.data

	def getPack(self):
		str = ""
		for x in range(1,6):
			str = str + ""
		return str



