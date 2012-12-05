
package service;

import javax.xml.bind.JAXBElement;
import javax.xml.bind.annotation.XmlElementDecl;
import javax.xml.bind.annotation.XmlRegistry;
import javax.xml.namespace.QName;


/**
 * This object contains factory methods for each 
 * Java content interface and Java element interface 
 * generated in the service package. 
 * <p>An ObjectFactory allows you to programatically 
 * construct new instances of the Java representation 
 * for XML content. The Java representation of XML 
 * content can consist of schema derived interfaces 
 * and classes representing the binding of schema 
 * type definitions, element declarations and model 
 * groups.  Factory methods for each of these are 
 * provided in this class.
 * 
 */
@XmlRegistry
public class ObjectFactory {

    private final static QName _LogoutResponse_QNAME = new QName("http://service/", "logoutResponse");
    private final static QName _GetCommentsForResponse_QNAME = new QName("http://service/", "getCommentsForResponse");
    private final static QName _AddToCart_QNAME = new QName("http://service/", "addToCart");
    private final static QName _RegisterResponse_QNAME = new QName("http://service/", "registerResponse");
    private final static QName _Login_QNAME = new QName("http://service/", "login");
    private final static QName _GetRatingsForResponse_QNAME = new QName("http://service/", "getRatingsForResponse");
    private final static QName _Leave_QNAME = new QName("http://service/", "leave");
    private final static QName _GetRatingsFor_QNAME = new QName("http://service/", "getRatingsFor");
    private final static QName _GetBuyListFor_QNAME = new QName("http://service/", "getBuyListFor");
    private final static QName _LoggedInResponse_QNAME = new QName("http://service/", "loggedInResponse");
    private final static QName _GetBuyListForResponse_QNAME = new QName("http://service/", "getBuyListForResponse");
    private final static QName _SetRatingForResponse_QNAME = new QName("http://service/", "setRatingForResponse");
    private final static QName _RemoveFromCartResponse_QNAME = new QName("http://service/", "removeFromCartResponse");
    private final static QName _ValidUsernameResponse_QNAME = new QName("http://service/", "validUsernameResponse");
    private final static QName _Checkout_QNAME = new QName("http://service/", "checkout");
    private final static QName _CheckoutResponse_QNAME = new QName("http://service/", "checkoutResponse");
    private final static QName _ValidPasswordResponse_QNAME = new QName("http://service/", "validPasswordResponse");
    private final static QName _AddToCartResponse_QNAME = new QName("http://service/", "addToCartResponse");
    private final static QName _GetItems_QNAME = new QName("http://service/", "getItems");
    private final static QName _ValidUsername_QNAME = new QName("http://service/", "validUsername");
    private final static QName _Logout_QNAME = new QName("http://service/", "logout");
    private final static QName _GetCurrentCostPlusResponse_QNAME = new QName("http://service/", "getCurrentCostPlusResponse");
    private final static QName _GetCommentsFor_QNAME = new QName("http://service/", "getCommentsFor");
    private final static QName _GetCurrentCostResponse_QNAME = new QName("http://service/", "getCurrentCostResponse");
    private final static QName _Register_QNAME = new QName("http://service/", "register");
    private final static QName _GetCurrentCostPlus_QNAME = new QName("http://service/", "getCurrentCostPlus");
    private final static QName _TestConnectionResponse_QNAME = new QName("http://service/", "testConnectionResponse");
    private final static QName _SetRatingFor_QNAME = new QName("http://service/", "setRatingFor");
    private final static QName _SetCommentFor_QNAME = new QName("http://service/", "setCommentFor");
    private final static QName _LoggedIn_QNAME = new QName("http://service/", "loggedIn");
    private final static QName _LeaveResponse_QNAME = new QName("http://service/", "leaveResponse");
    private final static QName _TestConnection_QNAME = new QName("http://service/", "testConnection");
    private final static QName _GetCurrentCost_QNAME = new QName("http://service/", "getCurrentCost");
    private final static QName _SetCommentForResponse_QNAME = new QName("http://service/", "setCommentForResponse");
    private final static QName _RemoveFromCart_QNAME = new QName("http://service/", "removeFromCart");
    private final static QName _ValidPassword_QNAME = new QName("http://service/", "validPassword");
    private final static QName _LoginResponse_QNAME = new QName("http://service/", "loginResponse");
    private final static QName _GetItemsResponse_QNAME = new QName("http://service/", "getItemsResponse");

    /**
     * Create a new ObjectFactory that can be used to create new instances of schema derived classes for package: service
     * 
     */
    public ObjectFactory() {
    }

    /**
     * Create an instance of {@link GetCurrentCostPlus }
     * 
     */
    public GetCurrentCostPlus createGetCurrentCostPlus() {
        return new GetCurrentCostPlus();
    }

    /**
     * Create an instance of {@link GetCurrentCostResponse }
     * 
     */
    public GetCurrentCostResponse createGetCurrentCostResponse() {
        return new GetCurrentCostResponse();
    }

    /**
     * Create an instance of {@link GetItems }
     * 
     */
    public GetItems createGetItems() {
        return new GetItems();
    }

    /**
     * Create an instance of {@link RegisterResponse }
     * 
     */
    public RegisterResponse createRegisterResponse() {
        return new RegisterResponse();
    }

    /**
     * Create an instance of {@link AddToCartResponse }
     * 
     */
    public AddToCartResponse createAddToCartResponse() {
        return new AddToCartResponse();
    }

    /**
     * Create an instance of {@link GetCommentsFor }
     * 
     */
    public GetCommentsFor createGetCommentsFor() {
        return new GetCommentsFor();
    }

    /**
     * Create an instance of {@link SetRatingForResponse }
     * 
     */
    public SetRatingForResponse createSetRatingForResponse() {
        return new SetRatingForResponse();
    }

    /**
     * Create an instance of {@link GetCommentsForResponse }
     * 
     */
    public GetCommentsForResponse createGetCommentsForResponse() {
        return new GetCommentsForResponse();
    }

    /**
     * Create an instance of {@link GetRatingsFor }
     * 
     */
    public GetRatingsFor createGetRatingsFor() {
        return new GetRatingsFor();
    }

    /**
     * Create an instance of {@link LeaveResponse }
     * 
     */
    public LeaveResponse createLeaveResponse() {
        return new LeaveResponse();
    }

    /**
     * Create an instance of {@link LoggedInResponse }
     * 
     */
    public LoggedInResponse createLoggedInResponse() {
        return new LoggedInResponse();
    }

    /**
     * Create an instance of {@link GetCurrentCostPlusResponse }
     * 
     */
    public GetCurrentCostPlusResponse createGetCurrentCostPlusResponse() {
        return new GetCurrentCostPlusResponse();
    }

    /**
     * Create an instance of {@link SetCommentFor }
     * 
     */
    public SetCommentFor createSetCommentFor() {
        return new SetCommentFor();
    }

    /**
     * Create an instance of {@link LoginResponse }
     * 
     */
    public LoginResponse createLoginResponse() {
        return new LoginResponse();
    }

    /**
     * Create an instance of {@link SetRatingFor }
     * 
     */
    public SetRatingFor createSetRatingFor() {
        return new SetRatingFor();
    }

    /**
     * Create an instance of {@link Login }
     * 
     */
    public Login createLogin() {
        return new Login();
    }

    /**
     * Create an instance of {@link GetItemsResponse }
     * 
     */
    public GetItemsResponse createGetItemsResponse() {
        return new GetItemsResponse();
    }

    /**
     * Create an instance of {@link SetCommentForResponse }
     * 
     */
    public SetCommentForResponse createSetCommentForResponse() {
        return new SetCommentForResponse();
    }

    /**
     * Create an instance of {@link Checkout }
     * 
     */
    public Checkout createCheckout() {
        return new Checkout();
    }

    /**
     * Create an instance of {@link Leave }
     * 
     */
    public Leave createLeave() {
        return new Leave();
    }

    /**
     * Create an instance of {@link ValidUsernameResponse }
     * 
     */
    public ValidUsernameResponse createValidUsernameResponse() {
        return new ValidUsernameResponse();
    }

    /**
     * Create an instance of {@link ValidPasswordResponse }
     * 
     */
    public ValidPasswordResponse createValidPasswordResponse() {
        return new ValidPasswordResponse();
    }

    /**
     * Create an instance of {@link GetBuyListFor }
     * 
     */
    public GetBuyListFor createGetBuyListFor() {
        return new GetBuyListFor();
    }

    /**
     * Create an instance of {@link TestConnection }
     * 
     */
    public TestConnection createTestConnection() {
        return new TestConnection();
    }

    /**
     * Create an instance of {@link RemoveFromCart }
     * 
     */
    public RemoveFromCart createRemoveFromCart() {
        return new RemoveFromCart();
    }

    /**
     * Create an instance of {@link GetRatingsForResponse }
     * 
     */
    public GetRatingsForResponse createGetRatingsForResponse() {
        return new GetRatingsForResponse();
    }

    /**
     * Create an instance of {@link CheckoutResponse }
     * 
     */
    public CheckoutResponse createCheckoutResponse() {
        return new CheckoutResponse();
    }

    /**
     * Create an instance of {@link ValidPassword }
     * 
     */
    public ValidPassword createValidPassword() {
        return new ValidPassword();
    }

    /**
     * Create an instance of {@link GetBuyListForResponse }
     * 
     */
    public GetBuyListForResponse createGetBuyListForResponse() {
        return new GetBuyListForResponse();
    }

    /**
     * Create an instance of {@link LoggedIn }
     * 
     */
    public LoggedIn createLoggedIn() {
        return new LoggedIn();
    }

    /**
     * Create an instance of {@link TestConnectionResponse }
     * 
     */
    public TestConnectionResponse createTestConnectionResponse() {
        return new TestConnectionResponse();
    }

    /**
     * Create an instance of {@link Register }
     * 
     */
    public Register createRegister() {
        return new Register();
    }

    /**
     * Create an instance of {@link RemoveFromCartResponse }
     * 
     */
    public RemoveFromCartResponse createRemoveFromCartResponse() {
        return new RemoveFromCartResponse();
    }

    /**
     * Create an instance of {@link GetCurrentCost }
     * 
     */
    public GetCurrentCost createGetCurrentCost() {
        return new GetCurrentCost();
    }

    /**
     * Create an instance of {@link Logout }
     * 
     */
    public Logout createLogout() {
        return new Logout();
    }

    /**
     * Create an instance of {@link LogoutResponse }
     * 
     */
    public LogoutResponse createLogoutResponse() {
        return new LogoutResponse();
    }

    /**
     * Create an instance of {@link AddToCart }
     * 
     */
    public AddToCart createAddToCart() {
        return new AddToCart();
    }

    /**
     * Create an instance of {@link ValidUsername }
     * 
     */
    public ValidUsername createValidUsername() {
        return new ValidUsername();
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link LogoutResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "logoutResponse")
    public JAXBElement<LogoutResponse> createLogoutResponse(LogoutResponse value) {
        return new JAXBElement<LogoutResponse>(_LogoutResponse_QNAME, LogoutResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetCommentsForResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "getCommentsForResponse")
    public JAXBElement<GetCommentsForResponse> createGetCommentsForResponse(GetCommentsForResponse value) {
        return new JAXBElement<GetCommentsForResponse>(_GetCommentsForResponse_QNAME, GetCommentsForResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link AddToCart }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "addToCart")
    public JAXBElement<AddToCart> createAddToCart(AddToCart value) {
        return new JAXBElement<AddToCart>(_AddToCart_QNAME, AddToCart.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link RegisterResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "registerResponse")
    public JAXBElement<RegisterResponse> createRegisterResponse(RegisterResponse value) {
        return new JAXBElement<RegisterResponse>(_RegisterResponse_QNAME, RegisterResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link Login }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "login")
    public JAXBElement<Login> createLogin(Login value) {
        return new JAXBElement<Login>(_Login_QNAME, Login.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetRatingsForResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "getRatingsForResponse")
    public JAXBElement<GetRatingsForResponse> createGetRatingsForResponse(GetRatingsForResponse value) {
        return new JAXBElement<GetRatingsForResponse>(_GetRatingsForResponse_QNAME, GetRatingsForResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link Leave }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "leave")
    public JAXBElement<Leave> createLeave(Leave value) {
        return new JAXBElement<Leave>(_Leave_QNAME, Leave.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetRatingsFor }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "getRatingsFor")
    public JAXBElement<GetRatingsFor> createGetRatingsFor(GetRatingsFor value) {
        return new JAXBElement<GetRatingsFor>(_GetRatingsFor_QNAME, GetRatingsFor.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetBuyListFor }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "getBuyListFor")
    public JAXBElement<GetBuyListFor> createGetBuyListFor(GetBuyListFor value) {
        return new JAXBElement<GetBuyListFor>(_GetBuyListFor_QNAME, GetBuyListFor.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link LoggedInResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "loggedInResponse")
    public JAXBElement<LoggedInResponse> createLoggedInResponse(LoggedInResponse value) {
        return new JAXBElement<LoggedInResponse>(_LoggedInResponse_QNAME, LoggedInResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetBuyListForResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "getBuyListForResponse")
    public JAXBElement<GetBuyListForResponse> createGetBuyListForResponse(GetBuyListForResponse value) {
        return new JAXBElement<GetBuyListForResponse>(_GetBuyListForResponse_QNAME, GetBuyListForResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link SetRatingForResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "setRatingForResponse")
    public JAXBElement<SetRatingForResponse> createSetRatingForResponse(SetRatingForResponse value) {
        return new JAXBElement<SetRatingForResponse>(_SetRatingForResponse_QNAME, SetRatingForResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link RemoveFromCartResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "removeFromCartResponse")
    public JAXBElement<RemoveFromCartResponse> createRemoveFromCartResponse(RemoveFromCartResponse value) {
        return new JAXBElement<RemoveFromCartResponse>(_RemoveFromCartResponse_QNAME, RemoveFromCartResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link ValidUsernameResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "validUsernameResponse")
    public JAXBElement<ValidUsernameResponse> createValidUsernameResponse(ValidUsernameResponse value) {
        return new JAXBElement<ValidUsernameResponse>(_ValidUsernameResponse_QNAME, ValidUsernameResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link Checkout }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "checkout")
    public JAXBElement<Checkout> createCheckout(Checkout value) {
        return new JAXBElement<Checkout>(_Checkout_QNAME, Checkout.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link CheckoutResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "checkoutResponse")
    public JAXBElement<CheckoutResponse> createCheckoutResponse(CheckoutResponse value) {
        return new JAXBElement<CheckoutResponse>(_CheckoutResponse_QNAME, CheckoutResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link ValidPasswordResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "validPasswordResponse")
    public JAXBElement<ValidPasswordResponse> createValidPasswordResponse(ValidPasswordResponse value) {
        return new JAXBElement<ValidPasswordResponse>(_ValidPasswordResponse_QNAME, ValidPasswordResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link AddToCartResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "addToCartResponse")
    public JAXBElement<AddToCartResponse> createAddToCartResponse(AddToCartResponse value) {
        return new JAXBElement<AddToCartResponse>(_AddToCartResponse_QNAME, AddToCartResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetItems }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "getItems")
    public JAXBElement<GetItems> createGetItems(GetItems value) {
        return new JAXBElement<GetItems>(_GetItems_QNAME, GetItems.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link ValidUsername }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "validUsername")
    public JAXBElement<ValidUsername> createValidUsername(ValidUsername value) {
        return new JAXBElement<ValidUsername>(_ValidUsername_QNAME, ValidUsername.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link Logout }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "logout")
    public JAXBElement<Logout> createLogout(Logout value) {
        return new JAXBElement<Logout>(_Logout_QNAME, Logout.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetCurrentCostPlusResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "getCurrentCostPlusResponse")
    public JAXBElement<GetCurrentCostPlusResponse> createGetCurrentCostPlusResponse(GetCurrentCostPlusResponse value) {
        return new JAXBElement<GetCurrentCostPlusResponse>(_GetCurrentCostPlusResponse_QNAME, GetCurrentCostPlusResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetCommentsFor }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "getCommentsFor")
    public JAXBElement<GetCommentsFor> createGetCommentsFor(GetCommentsFor value) {
        return new JAXBElement<GetCommentsFor>(_GetCommentsFor_QNAME, GetCommentsFor.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetCurrentCostResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "getCurrentCostResponse")
    public JAXBElement<GetCurrentCostResponse> createGetCurrentCostResponse(GetCurrentCostResponse value) {
        return new JAXBElement<GetCurrentCostResponse>(_GetCurrentCostResponse_QNAME, GetCurrentCostResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link Register }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "register")
    public JAXBElement<Register> createRegister(Register value) {
        return new JAXBElement<Register>(_Register_QNAME, Register.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetCurrentCostPlus }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "getCurrentCostPlus")
    public JAXBElement<GetCurrentCostPlus> createGetCurrentCostPlus(GetCurrentCostPlus value) {
        return new JAXBElement<GetCurrentCostPlus>(_GetCurrentCostPlus_QNAME, GetCurrentCostPlus.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link TestConnectionResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "testConnectionResponse")
    public JAXBElement<TestConnectionResponse> createTestConnectionResponse(TestConnectionResponse value) {
        return new JAXBElement<TestConnectionResponse>(_TestConnectionResponse_QNAME, TestConnectionResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link SetRatingFor }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "setRatingFor")
    public JAXBElement<SetRatingFor> createSetRatingFor(SetRatingFor value) {
        return new JAXBElement<SetRatingFor>(_SetRatingFor_QNAME, SetRatingFor.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link SetCommentFor }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "setCommentFor")
    public JAXBElement<SetCommentFor> createSetCommentFor(SetCommentFor value) {
        return new JAXBElement<SetCommentFor>(_SetCommentFor_QNAME, SetCommentFor.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link LoggedIn }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "loggedIn")
    public JAXBElement<LoggedIn> createLoggedIn(LoggedIn value) {
        return new JAXBElement<LoggedIn>(_LoggedIn_QNAME, LoggedIn.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link LeaveResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "leaveResponse")
    public JAXBElement<LeaveResponse> createLeaveResponse(LeaveResponse value) {
        return new JAXBElement<LeaveResponse>(_LeaveResponse_QNAME, LeaveResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link TestConnection }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "testConnection")
    public JAXBElement<TestConnection> createTestConnection(TestConnection value) {
        return new JAXBElement<TestConnection>(_TestConnection_QNAME, TestConnection.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetCurrentCost }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "getCurrentCost")
    public JAXBElement<GetCurrentCost> createGetCurrentCost(GetCurrentCost value) {
        return new JAXBElement<GetCurrentCost>(_GetCurrentCost_QNAME, GetCurrentCost.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link SetCommentForResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "setCommentForResponse")
    public JAXBElement<SetCommentForResponse> createSetCommentForResponse(SetCommentForResponse value) {
        return new JAXBElement<SetCommentForResponse>(_SetCommentForResponse_QNAME, SetCommentForResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link RemoveFromCart }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "removeFromCart")
    public JAXBElement<RemoveFromCart> createRemoveFromCart(RemoveFromCart value) {
        return new JAXBElement<RemoveFromCart>(_RemoveFromCart_QNAME, RemoveFromCart.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link ValidPassword }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "validPassword")
    public JAXBElement<ValidPassword> createValidPassword(ValidPassword value) {
        return new JAXBElement<ValidPassword>(_ValidPassword_QNAME, ValidPassword.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link LoginResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "loginResponse")
    public JAXBElement<LoginResponse> createLoginResponse(LoginResponse value) {
        return new JAXBElement<LoginResponse>(_LoginResponse_QNAME, LoginResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetItemsResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://service/", name = "getItemsResponse")
    public JAXBElement<GetItemsResponse> createGetItemsResponse(GetItemsResponse value) {
        return new JAXBElement<GetItemsResponse>(_GetItemsResponse_QNAME, GetItemsResponse.class, null, value);
    }

}
