#pragma once
class ISortMethods {
public:
	/// <summary>
	/// Ordena los n�meros de algun arreglo de tipo INT32
	/// </summary>
	/// <param name="array">Arrreglo a ordenar</param>
	/// <param name="nElements">N�mero de elementos dentro del array</param>
	virtual void sortNumber(int *, int) = 0;
};