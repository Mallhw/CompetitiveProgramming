template <typename T, typename U>
ostream& operator<< (ostream& os, const pair<T, U>& x){
    os << "(" << x.first << ", " << x.second << ")";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const map<T, U>& arr){
	os << "{\n";
    for(const pair<T,U>& x : arr){
		os << "    " << x << endll;
	}
	os << "}";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const unordered_map<T, U>& arr){
    os << "{\n";
    for(const pair<T,U>& x : arr){
        os << "    " << x << endll;
    }
    os << "}";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const multimap<T, U>& arr){
    os << "{\n";
    for(const pair<T,U>& x : arr){
        os << "    " << x << endll;
    }
    os << "}";
    return os;
    
}