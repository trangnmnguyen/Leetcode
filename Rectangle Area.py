class Solution: 
	def computeArea(self, A, B, C, D, E, F, G, H):
		fst_corner_x = max(A, E)
		fst_corner_y = max(B, F)
		snd_corner_x = min(C, G)
		snd_corner_y = min(D, H)
		overlapping_area = (snd_corner_x - fst_corner_x) * (snd_corner_y - fst_corner_y)
		rectilinear = (C - A) * (D - B) + (G - E) * (H - F) + overlapping_area