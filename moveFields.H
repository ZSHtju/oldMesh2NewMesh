{
	forAll(newMesh.C(),celli)
	{
		vector c(newMesh.C()[celli].y(),newMesh.C()[celli].z(),newMesh.C()[celli].x());
		label icell = mesh.findCell(c); 
		if(icell > 0)
		{
			NMp[celli] = p[icell];
			NMT[celli] = T[icell];
			NMk[celli] = turbulence->k()()[icell];
			NMnut[celli] = turbulence->nut()()[icell];
			NMalphat[celli] = turbulence->alphat()()[icell];
			forAll(NMY,i)
			{
				NMY[i][celli] = Y[i][icell];
			}
		}
	}
		
}


// write fields
NMp.write();
NMT.write();
NMk.write();
NMnut.write();
NMalphat.write();
forAll(NMY,i)
{
	NMY[i].write();
}