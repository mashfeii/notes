enum class HttpError { OK = 204 };
enum NormalError {SUCCESS};

int main() {
  HttpError error = HttpError::OK;
  int num = error;
  NormalError succes = NormalError::SUCCESS;
  int numbered = succes;
}
