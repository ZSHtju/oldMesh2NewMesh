
fvMesh newMesh
(
	IOobject
	(
		"newMesh",
        runTime.timeName(),
        runTime,
		IOobject::MUST_READ,
		IOobject::NO_WRITE
	)
);	

{
    volScalarField Ydefault
    (
        IOobject
        (
            "Ydefault",
            runTime.timeName(),
            newMesh,
            IOobject::READ_IF_PRESENT,
            IOobject::NO_WRITE,
            false
        ),
        newMesh,
        dimensionedScalar(dimless, 1)
    );

    Ydefault.write();

    volScalarField p
    (
        IOobject
        (
            "p",
            runTime.timeName(),
            newMesh,
            IOobject::READ_IF_PRESENT,
            IOobject::NO_WRITE,
            false
        ),
        newMesh,
        dimensionedScalar(dimPressure, 101325)
    );

    p.write();

    volScalarField T 
    (
        IOobject
        (
            "T",
            runTime.timeName(),
            newMesh,
            IOobject::READ_IF_PRESENT,
            IOobject::NO_WRITE,
            false
        ),
        newMesh,
        dimensionedScalar(dimTemperature, 300)
    );

    T.write();
}


autoPtr<psiReactionThermo> newMeshThermo(psiReactionThermo::New(newMesh));
psiReactionThermo& NMThermo = newMeshThermo();
NMThermo.validate(args.executable(), "e","h");

basicSpecieMixture& NMComposition = NMThermo.composition();
PtrList<volScalarField>& NMY = NMComposition.Y();

volScalarField NMp
(
	IOobject
	(
		"p",
		runTime.timeName(),
		newMesh,
		IOobject::READ_IF_PRESENT,
		IOobject::AUTO_WRITE,
		false
	),
	newMesh,
	dimensionedScalar(dimPressure, 101325)
);

volScalarField NMT
(
	IOobject
	(
		"T",
		runTime.timeName(),
		newMesh,
		IOobject::READ_IF_PRESENT,
		IOobject::AUTO_WRITE,
		false
	),
	newMesh,
	dimensionedScalar(dimTemperature, 300)
);

volVectorField NMU
(
	IOobject
	(
		"U",
		runTime.timeName(),
		newMesh,
		IOobject::READ_IF_PRESENT,
		IOobject::AUTO_WRITE,
		false
	),
	newMesh,
	dimensionedVector(dimVelocity, vector::zero)
);


volScalarField NMk
(
	IOobject
	(
		"k",
		runTime.timeName(),
		newMesh,
		IOobject::READ_IF_PRESENT,
		IOobject::AUTO_WRITE,
		false
	),
	newMesh,
	dimensionedScalar(dimensionSet(0, 2, -2, 0, 0, 0, 0), 0)
);

volScalarField NMnut
(
	IOobject
	(
		"nut",
		runTime.timeName(),
		newMesh,
		IOobject::READ_IF_PRESENT,
		IOobject::AUTO_WRITE,
		false
	),
	newMesh,
	dimensionedScalar(dimensionSet(0, 2, -1, 0, 0, 0, 0), 0)
);


volScalarField NMalphat
(
	IOobject
	(
		"alphat",
		runTime.timeName(),
		newMesh,
		IOobject::READ_IF_PRESENT,
		IOobject::AUTO_WRITE,
		false
	),
	newMesh,
	dimensionedScalar(dimensionSet(1, -1, -1, 0, 0, 0, 0), 0)
);
