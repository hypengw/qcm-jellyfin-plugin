use jellyfin_api::apis::user_api;

pub fn login() {
    user_api::authenticate_user_by_name(configuration, params);
}
